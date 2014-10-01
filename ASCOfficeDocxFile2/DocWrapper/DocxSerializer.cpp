#include "DocxSerializer.h"

#include "../../DesktopEditor/common/Directory.h"
#include "../../DesktopEditor/common/File.h"
#include "../BinWriter/BinWriters.h"
#include "../BinReader/Readers.h"

#ifndef _WIN32
#include "../../DesktopEditor/common/Types.h"
#endif

int BinDocxRW::g_nCurFormatVersion = 0;

BinDocxRW::CDocxSerializer::CDocxSerializer()
{
	m_oBinaryFileWriter = NULL;
	m_pCurFileWriter = NULL;
	m_bIsNoBase64Save = false;
	m_bSaveChartAsImg = false;
}
bool BinDocxRW::CDocxSerializer::saveToFile(CString& sSrcFileName, CString& sDstPath, CString& sXMLOptions)
{
	//create mediadir
	OOX::CPath path(sSrcFileName);
	CString mediaDir = path.GetDirectory() + _T("media\\");
	NSDirectory::CreateDirectory(string2std_string(mediaDir));

	NSBinPptxRW::CDrawingConverter oDrawingConverter;
	NSBinPptxRW::CBinaryFileWriter& oBufferedStream = *oDrawingConverter.m_pBinaryWriter;

#ifdef _WIN32
	DocWrapper::FontProcessor fp;
	fp.setFontDir(m_sFontDir);
	PPTXFile::IOfficeFontPicker* pFontPicker = NULL;
	CoCreateInstance(__uuidof(PPTXFile::COfficeFontPicker), NULL, CLSCTX_ALL, __uuidof(PPTXFile::IOfficeFontPicker), (void**)(&pFontPicker));
	BSTR bstrFontDir1 = m_sFontDir.AllocSysString();
	pFontPicker->Init(bstrFontDir1);
	SysFreeString(bstrFontDir1);
	NSFontCutter::CEmbeddedFontsManager* pEmbeddedFontsManager = NULL;
	if(false == m_sEmbeddedFontsDir.IsEmpty())
	{
		NSDirectory::CreateDirectory(string2std_string(m_sEmbeddedFontsDir));

		BSTR bstrEmbeddedFontsDirectory = m_sEmbeddedFontsDir.AllocSysString();
		pFontPicker->SetEmbeddedFontsDirectory(bstrEmbeddedFontsDirectory);
		SysFreeString(bstrEmbeddedFontsDirectory);

		VARIANT vt;
		pFontPicker->GetAdditionalParam(_T("NativeCutter"), &vt);
		pEmbeddedFontsManager = (NSFontCutter::CEmbeddedFontsManager*)vt.pvRecord;

		//��������� ���� ��������� ������� ��� �������.
		pEmbeddedFontsManager->CheckString(CString(_T("abcdefghijklmnopqrstuvwxyz")));

		//������� ���� �����
		pEmbeddedFontsManager->CheckFont(_T("Wingdings 3"), fp.getFontManager());
		pEmbeddedFontsManager->CheckFont(_T("Arial"), fp.getFontManager());
		//pEmbeddedFontsManager ����������� ��� �����
	}

	oDrawingConverter.SetFontDir(m_sFontDir);
	VARIANT vt;
	vt.vt = VT_UNKNOWN;
	vt.punkVal = pFontPicker;
	oDrawingConverter.SetAdditionalParam(CString(_T("FontPicker")), vt);
	oDrawingConverter.SetMainDocument(this);
	oDrawingConverter.SetMediaDstPath(mediaDir);
	ParamsWriter oParamsWriter(oBufferedStream, fp, &oDrawingConverter, pEmbeddedFontsManager);
	m_oBinaryFileWriter = new BinaryFileWriter(oParamsWriter);
	m_oBinaryFileWriter->intoBindoc(sDstPath);
#endif
	BYTE* pbBinBuffer = oBufferedStream.GetBuffer();
	int nBinBufferLen = oBufferedStream.GetPosition();

	if (m_bIsNoBase64Save)
	{
		NSFile::CFileBinary oFile;
		oFile.CreateFileW(string2std_string(sSrcFileName));
		oFile.WriteFile(pbBinBuffer, nBinBufferLen);
		oFile.CloseFile();
	}
	else
	{
		int nBase64BufferLen = Base64::Base64EncodeGetRequiredLength(nBinBufferLen, Base64::B64_BASE64_FLAG_NOCRLF);
		BYTE* pbBase64Buffer = new BYTE[nBase64BufferLen];
		if(TRUE == Base64::Base64Encode(pbBinBuffer, nBinBufferLen, (LPSTR)pbBase64Buffer, &nBase64BufferLen, Base64::B64_BASE64_FLAG_NOCRLF))
		{
			NSFile::CFileBinary oFile;
			oFile.CreateFileW(string2std_string(sSrcFileName));
			oFile.WriteStringUTF8(string2std_string(m_oBinaryFileWriter->WriteFileHeader(nBinBufferLen)));
			oFile.WriteFile(pbBase64Buffer, nBase64BufferLen);
			oFile.CloseFile();
		}
	}
	RELEASEOBJECT(m_oBinaryFileWriter);
	RELEASEINTERFACE(pFontPicker);
	return true;
}
bool BinDocxRW::CDocxSerializer::loadFromFile(CString& sSrcFileName, CString& sDstPath, CString& sXMLOptions, CString& sThemePath, CString& sMediaPath)
{
	bool bResultOk = false;
	NSFile::CFileBinary oFile;
	if(oFile.OpenFile(string2std_string(sSrcFileName)))
	{
		DWORD nBase64DataSize = 0;
		BYTE* pBase64Data = new BYTE[oFile.GetFileSize()];
		oFile.ReadFile(pBase64Data, oFile.GetFileSize(), nBase64DataSize);
		oFile.CloseFile();

		//��������� ������
		bool bValidFormat = false;
		CString sSignature(g_sFormatSignature);
		int nSigLength = sSignature.GetLength();
		if(nBase64DataSize > nSigLength)
		{
			CStringA sCurSig((char*)pBase64Data, nSigLength);
			if((CStringA)sSignature == sCurSig)
			{
				bValidFormat = true;
			}
		}
		if(bValidFormat)
		{
			//������ �� ����� ������ � ����� base64
			int nIndex = nSigLength;
			int nType = 0;
			CStringA version = "";
			CStringA dst_len = "";
			while (true)
			{
				nIndex++;
				BYTE _c = pBase64Data[nIndex];
				if (_c == ';')
				{

					if(0 == nType)
					{
						nType = 1;
						continue;
					}
					else
					{
						nIndex++;
						break;
					}
				}
				if(0 == nType)
					version.AppendChar(_c);
				else
					dst_len.AppendChar(_c);
			}
			int nDataSize = atoi(dst_len);
			BYTE* pData = new BYTE[nDataSize];
			if(FALSE != Base64::Base64Decode((LPCSTR)(pBase64Data + nIndex), nBase64DataSize - nIndex, pData, &nDataSize))
			{
				NSBinPptxRW::CDrawingConverter oDrawingConverter;
				NSBinPptxRW::CBinaryFileReader& oBufferedStream = *oDrawingConverter.m_pReader;
				oBufferedStream.Init(pData, 0, nDataSize);

				int nVersion = g_nFormatVersion;
				if(version.GetLength() > 0)
				{
					version = version.Right(version.GetLength() - 1);
					int nTempVersion = atoi(version);
					if(0 != nTempVersion)
					{
						g_nCurFormatVersion = nVersion = nTempVersion;
					}
				}
				oDrawingConverter.SetMainDocument(this);
				oDrawingConverter.SetMediaDstPath(sMediaPath);
				m_pCurFileWriter = new Writers::FileWriter(sDstPath, m_sFontDir, nVersion, m_bSaveChartAsImg, &oDrawingConverter, sThemePath);

				//����� � ����������
				TCHAR tFolder[256];
				TCHAR tDrive[256];
				_tsplitpath( sSrcFileName, tDrive, tFolder, NULL, NULL );
				CString sFolder = CString(tFolder);
				CString sDrive = CString(tDrive);
				CString sFileInDir = sDrive + sFolder;

				VARIANT var;
				var.vt = VT_BSTR;
				var.bstrVal = sFileInDir.AllocSysString();
				oDrawingConverter.SetAdditionalParam(CString(L"SourceFileDir"), var);
				RELEASESYSSTRING(var.bstrVal);

				BinaryFileReader oBinaryFileReader(sFileInDir, oBufferedStream, *m_pCurFileWriter);
				oBinaryFileReader.ReadFile();

				VARIANT vt;
				oDrawingConverter.GetAdditionalParam(CString(_T("ContentTypes")), &vt);
				if(VT_BSTR == vt.vt)
					m_pCurFileWriter->m_oContentTypesWriter.AddOverrideRaw(CString(vt.bstrVal));

				m_pCurFileWriter->m_oCommentsWriter.Write();
				m_pCurFileWriter->m_oChartWriter.Write();
				m_pCurFileWriter->m_oStylesWriter.Write();
				m_pCurFileWriter->m_oNumberingWriter.Write();
				m_pCurFileWriter->m_oFontTableWriter.Write();
				m_pCurFileWriter->m_oHeaderFooterWriter.Write();
				//Setting ����� ����� HeaderFooter, ����� ��������� evenAndOddHeaders
				m_pCurFileWriter->m_oSettingWriter.Write();
				//Document ����� ����� HeaderFooter, ����� ��������� sectPr
				m_pCurFileWriter->m_oDocumentWriter.Write();
				//Rels � ContentTypes ����� � �����
				//m_pCurFileWriter->m_oDocumentRelsWriter.Write(_T("document.xml.rels"));
				m_pCurFileWriter->m_oContentTypesWriter.Write();

				//CSerializer oSerializer = CSerializer();
				//if(false != oSerializer.Write(oBufferedStream, sDirectoryOut))
				//{
				bResultOk = true;
				//}
			}
		}
		RELEASEARRAYOBJECTS(pBase64Data);
	}
	return bResultOk;
}
bool BinDocxRW::CDocxSerializer::getXmlContent(NSBinPptxRW::CBinaryFileReader& oBufferedStream, long lLength, CString& sOutputXml)
{
	long nLength = oBufferedStream.GetLong();
	Writers::ContentWriter oTempContentWriter;
	BinDocxRW::Binary_DocumentTableReader oBinary_DocumentTableReader(oBufferedStream, *m_pCurFileWriter, oTempContentWriter, NULL);
	int res = oBinary_DocumentTableReader.Read1(nLength, &BinDocxRW::Binary_DocumentTableReader::ReadDocumentContent, &oBinary_DocumentTableReader, NULL);

	sOutputXml = oTempContentWriter.m_oContent.GetData().GetString();
	return true;
}
bool BinDocxRW::CDocxSerializer::getBinaryContent(CString& bsTxContent, NSBinPptxRW::CBinaryFileWriter& oBufferedStream, long& lDataSize)
{
	if(NULL == m_oBinaryFileWriter)
		return false;
	long nStartPos = oBufferedStream.GetPosition();

	XmlUtils::CXmlLiteReader oReader;
	oReader.FromString(bsTxContent);
	oReader.ReadNextNode();//v:textbox
	CString sRootName = oReader.GetName();
	if(_T("v:textbox") == sRootName)
		oReader.ReadNextNode();//w:txbxContent

	OOX::Logic::CSdtContent oSdtContent;
	oSdtContent.fromXML(oReader);
	BinDocxRW::ParamsWriter oCurParamsWriter(m_oBinaryFileWriter->m_oParamsWriter);
	BinDocxRW::ParamsWriter oParamsWriter(oBufferedStream, oCurParamsWriter.m_oFontProcessor, oCurParamsWriter.m_pOfficeDrawingConverter, oCurParamsWriter.m_pEmbeddedFontsManager);
	oParamsWriter.m_poTheme = oCurParamsWriter.m_poTheme;
	oParamsWriter.m_oSettings = oCurParamsWriter.m_oSettings;
	oParamsWriter.m_pCurRels = oCurParamsWriter.m_pCurRels;
	oParamsWriter.m_sCurDocumentPath = oCurParamsWriter.m_sCurDocumentPath;

	BinDocxRW::BinaryCommonWriter oBinaryCommonWriter(oParamsWriter);
	int nCurPos = oBinaryCommonWriter.WriteItemWithLengthStart();
	BinDocxRW::BinaryDocumentTableWriter oBinaryDocumentTableWriter(oParamsWriter, BinDocxRW::ParamsDocumentWriter(oParamsWriter.m_pCurRels, oParamsWriter.m_sCurDocumentPath), NULL, NULL);
	oBinaryDocumentTableWriter.WriteDocumentContent(oSdtContent.m_arrItems);
	oBinaryCommonWriter.WriteItemWithLengthEnd(nCurPos);

	long nEndPos = oBufferedStream.GetPosition();
	lDataSize = nEndPos - nStartPos;
	return true;
}
void BinDocxRW::CDocxSerializer::setFontDir(CString& sFontDir)
{
	m_sFontDir = sFontDir;
}
void BinDocxRW::CDocxSerializer::setEmbeddedFontsDir(CString& sEmbeddedFontsDir)
{
	m_sEmbeddedFontsDir = sEmbeddedFontsDir;
}
void BinDocxRW::CDocxSerializer::setIsNoBase64Save(bool bIsNoBase64Save)
{
	m_bIsNoBase64Save = bIsNoBase64Save;
}
void BinDocxRW::CDocxSerializer::setSaveChartAsImg(bool bSaveChartAsImg)
{
	m_bSaveChartAsImg = bSaveChartAsImg;
}