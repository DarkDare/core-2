#include "precompiled_xls.h"
#include "OfficeArtRecordHeader.h"
#include <Binary/CFRecord.h>
#include <Binary/CFRecordType.h>

namespace ODRAW
{;


XLS::BiffStructurePtr OfficeArtRecordHeader::clone()
{
	return XLS::BiffStructurePtr(new OfficeArtRecordHeader(*this));
}
//
//
//void OfficeArtRecordHeader::setXMLAttributes(MSXML2::IXMLDOMElementPtr xml_tag)
//{
//}
//
//void OfficeArtRecordHeader::getXMLAttributes(MSXML2::IXMLDOMElementPtr xml_tag)
//{
//}
//

void OfficeArtRecordHeader::store(XLS::CFRecord& record)
{
	unsigned __int16 ver_inst;
	SETBITS(ver_inst, 0, 3, recVer);
	SETBITS(ver_inst, 4, 15, recInstance);
	record << ver_inst << recType;
	record.registerDelayedDataReceiver(NULL, sizeof(recLen), XLS::rt_MsoDrawing);
}


void OfficeArtRecordHeader::load(XLS::CFRecord& record)
{
	unsigned __int16 ver_inst;
	record >> ver_inst >> recType >> recLen;
	recVer = GETBITS(ver_inst, 0, 3);
	recInstance = GETBITS(ver_inst, 4, 15);
}


const size_t OfficeArtRecordHeader::size() const
{
	return sizeof(unsigned __int16) + sizeof(recType) + sizeof(recLen);
}

} // namespace XLS