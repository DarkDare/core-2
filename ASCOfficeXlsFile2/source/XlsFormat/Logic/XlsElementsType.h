#pragma once

namespace XLS
{

enum ElementType
{
    typeNone = 0,

	typeBiffRecord,
	typeBiffRecordContinued,
	typeBiffRecordSplit,

	typeCompositeObject,

//BiffRecord
	typeAnyObject = 1000,
	typeAreaFormat,
	typeAlRuns,
	typeArea,
	typeArray,
	typeAttachedLabel,
	typeAutoFilter,
	typeAutoFilter12,
	typeAutoFilterInfo,
	typeAxcExt,
	typeAxesUsed,
	typeAxis,
	typeAxisLine,
	typeAxisParent,
	typeBackup,
	typeBar,
	typeBegin,
	typeBigName,
	typeBkHim,
	typeBlank,
	typeBOF,
	typeBoolErr,
	typeBookBool,
	typeBookExt,
	typeBopPop,
	typeBopPopCustom,
	typeBottomMargin,
	typeBoundSheet8,
	typeBRAI,
	typeBuiltInFnGroupCount,
	typeCalcCount,
	typeCalcDelta,
	typeCalcIter,
	typeCalcMode,
	typeCalcPrecision,
	typeCalcRefMode,
	typeCalcSaveRecalc,
	typeCatLab,
	typeCatSerRange,
	typeCellWatch,
	typeCF,
	typeCF12,
	typeCFEx,
	typeChart,
	typeChart3d,
	typeChart3DBarShape,
	typeChartFormat,
	typeChartFrtInfo,
	typeCodeName,
	typeCodePage,
	typeColInfo,
	typeCompat12,
	typeCompressPictures,
	typeCondFmt,
	typeCondFmt12,
	typeContinue,
	typeContinueBigName,
	typeContinueFrt,
	typeContinueFrt11,
	typeContinueFrt12,
	typeCountry,
	typeCrErr,
	typeCRN,
	typeCrtLayout12,
	typeCrtLayout12A,
	typeCrtLine,
	typeCrtLink,
	typeCrtMlFrt,
	typeCrtMlFrtContinue,
	typeDat,
	typeDataFormat,
	typeDataLabExt,
	typeDataLabExtContents,
	typeDate1904,
	typeDBCell,
	typeDbOrParamQry,
	typeDBQueryExt,
	typeDCon,
	typeDConBin,
	typeDConn,
	typeDConName,
	typeDConRef,
	typeDefaultRowHeight,
	typeDefaultText,
	typeDefColWidth,
	typeDimensions,
	typeDocRoute,
	typeDropBar,
	typeDropDownObjIds,
	typeDSF,
	typeDv,
	typeDVal,
	typeDXF,
	typeDxGCol,
	typeEnd,
	typeEndObject,
	typeEntExU2,
	typeEOF_T,
	typeExcel9File,
	typeExternName,
	typeExternSheet,
	typeExtSST,
	typeExtString,
	typeFbi,
	typeFbi2,
	typeFeat,
	typeFeatHdr,
	typeFeatHdr11,
	typeFeature11,
	typeFeature12,
	typeFilePass,
	typeFileSharing,
	typeFilterMode,
	typeFnGroupName,
	typeFnGrp12,
	typeFont,
	typeFontX,
	typeFooter,
	typeForceFullCalculation,
	typeFormat,
	typeFormula,
	typeFrame,
	typeFrtFontList,
	typeGelFrame,
	typeGridSet,
	typeGUIDTypeLib,
	typeGuts,
	typeHCenter,
	typeHeader,
	typeHeaderFooter,
	typeHFPicture,
	typeHideObj,
	typeHLink,
	typeHLinkTooltip,
	typeHorizontalPageBreaks,
	typeIFmtRecord,
	typeIndex,
	typeInterfaceEnd,
	typeInterfaceHdr,
	typeIntl,
	typeLabel,
	typeLabelSst,
	typeLbl,
	typeLeftMargin,
	typeLegend,
	typeLegendException,
	typeLel,
	typeLine,
	typeLineFormat,
	typeList12,
	typeLPr,
	typeLRng,
	typeMarkerFormat,
	typeMDB,
	typeMDTInfo,
	typeMDXKPI,
	typeMDXProp,
	typeMDXSet,
	typeMDXStr,
	typeMDXTuple,
	typeMergeCells,
	typeMms,
	typeMsoDrawing,
	typeMsoDrawingGroup,
	typeMsoDrawingSelection,
	typeMTRSettings,
	typeMulBlank,
	typeMulRk,
	typeNameCmt,
	typeNameFnGrp12,
	typeNamePublish,
	typeNote,
	typeNumber,
	typeObj,
	typeObjectLink,
	typeObjProtect,
	typeObNoMacros,
	typeObProj,
	typeOleDbConn,
	typeOleObjectSize,
	typePalette,
	typePane,
	typePassword,
	typePhoneticInfo,
	typePicF,
	typePie,
	typePieFormat,
	typePivotChartBits,
	typePlotArea,
	typePlotGrowth,
	typePls,
	typePLV,
	typePos,
	typePrintGrid,
	typePrintRowCol,
	typePrintSize,
	typeProt4Rev,
	typeProt4RevPass,
	typeProtect,
	typeQsi,
	typeQsif,
	typeQsir,
	typeQsiSXTag,
	typeRadar,
	typeRadarArea,
	typeRealTimeData,
	typeRecalcId,
	typeRecipName,
	typeRefreshAll,
	typeRichTextStream,
	typeRightMargin,
	typeRGISeriesListSpecial,
	typeRK,
	typeRow,
	typeRRSort,
	typeRRTabId,
	typeSBaseRef,
	typeScatter,
	typeSCENARIO,
	typeScenarioProtect,
	typeScenMan,
	typeScl,
	typeSelection,
	typeSerAuxErrBar,
	typeSerAuxTrend,
	typeSerFmt,
	typeSeries,
	typeSeriesList,
	typeSeriesText,
	typeSerParent,
	typeSerToCrt,
	typeSetup,
	typeShapePropsStream,
	typeSheetExt,
	typeShrFmla,
	typeShtProps,
	typeSIIndex,
	typeSort,
	typeSortData,
	typeSST,
	typeStartObject,
	typeString,
	typeStyle,
	typeStyleExt,
	typeSupBook,
	typeSurf,
	typeSXAddl,
	typeSXDI,
	typeSxDXF,
	typeSXEx,
	typeSxFilt,
	typeSxFormat,
	typeSxItm,
	typeSxIvd,
	typeSXLI,
	typeSXPI,
	typeSXPIEx,
	typeSxRule,
	typeSxSelect,
	typeSXStreamID,
	typeSXString,
	typeSXTbl,
	typeSxTbpg,
	typeSXTBRGIITM,
	typeSXTH,
	typeSxvd,
	typeSXVDEx,
	typeSXVDTEx,
	typeSXVI,
	typeSxView,
	typeSXViewEx,
	typeSXViewEx9,
	typeSXViewLink,
	typeSXVS,
	typeSync,
	typeTable,
	typeTableStyle,
	typeTableStyleElement,
	typeTableStyles,
	typeTemplate,
	typeText,
	typeTextPropsStream,
	typeTheme,
	typeTick,
	typeTopMargin,
	typeTxO,
	typeTxtQry,
	typeUncalced,
	typeUnits,
	typeUserBView,
	typeUserSViewBegin,
	typeUserSViewEnd,
	typeUsesELFs,
	typeValueRange,
	typeVCenter,
	typeVerticalPageBreaks,
	typeWebPub,
	typeWindow1,
	typeWindow2,
	typeWinProtect,
	typeWOpt,
	typeWriteAccess,
	typeWriteProtect,
	typeWsBool,
	typeXCT,
	typeXF,
	typeXFCRC,
	typeXFExt,
	typeYMult,

	typeClrtClient,

//CompositeObject
	typeAI,
	typeATTACHEDLABEL,
	typeAUTOFILTER,
	typeAXES,
	typeAXISPARENT,
	typeAXM,
	typeAXS,
	typeBACKGROUND,
	typeBIGNAME,
	typeBUNDLESHEET,
	typeCELL,
	typeCELL_GROUP,
	typeCELLTABLE,
	typeCHART,
	typeCHARTFOMATS,
	typeCOLUMNS,
	typeCONDFMT,
	typeCONDFMT12,
	typeCONDFMTS,
	typeCRT,
	typeCRTMLFRT,
	typeCUSTOMVIEW,
	typeDAT,
	typeDBQUERY,
	typeDBQUERYEXT,
	typeDCON,
	typeDFTTEXT,
	typeDOCROUTE,
	typeDREF,
	typeDROPBAR,
	typeDVAL,
	typeDVAXIS,
	typeFEAT,
	typeFEAT11,
	typeFNGROUPS,
	typeFONTLIST,
	typeFORMATTING,
	typeFORMULA,
	typeFRAME,
	typeGELFRAME,
	typeGLOBALS,
	typeHLINK,
	typeINTERFACE_T,
	typeIVAXIS,
	typeLBL,
	typeLD,
	typeMACROSORTANDFILTER,
	typeMDBLOCK,
	typeMDTINFO,
	typeMDXSTR,
	typeMDXTUPLESET,
	typeMETADATA,
	typeMSODRAWINGGROUP,
	typeOBJ,
	typeOBJECTS,
	typePAGESETUP,
	typePHONETICINFO,
	typePICF,
	typePIVOTADDL,
	typePIVOTCACHEDEFINITION,
	typePIVOTCORE,
	typePIVOTEX,
	typePIVOTFORMAT,
	typePIVOTFRT,
	typePIVOTFRT9,
	typePIVOTIVD,
	typePIVOTLI,
	typePIVOTPI,
	typePIVOTRULE,
	typePIVOTSELECT,
	typePIVOTTH,
	typePIVOTVD,
	typePIVOTVDTEX,
	typePIVOTVIEW,
	typePIVOTVIEWEX,
	typePRFILTER,
	typePROTECTION,
	typePROTECTION_COMMON,
	typeQSIR,
	typeQUERYTABLE,
	typeRECORD12,
	typeRTD,
	typeSCENARIOS,
	typeSERIESAXIS,
	typeSERIESDATA,
	typeSERIESFORMAT,
	typeSHAPEPROPS,
	typeSHAREDSTRINGS,
	typeSHFMLA_SET,
	typeSORT,
	typeSORTANDFILTER,
	typeSORTDATA12,
	typeSS,
	typeSTYLES,
	typeSUB,
	typeSUPBOOK,
	typeSXADDLAUTOSORT,
	typeSXADDLCACHE,
	typeSXADDLCACHE12,
	typeSXADDLCACHEFIELD,
	typeSXADDLCACHEITEM,
	typeSXADDLCALCMEMBER,
	typeSXADDLCONDFMT,
	typeSXADDLCONDFMTS,
	typeSXADDLDBQUERY,
	typeSXADDLFIELD,
	typeSXADDLFIELD12,
	typeSXADDLGROUP,
	typeSXADDLGRPLEVEL,
	typeSXADDLHIERARCHY,
	typeSXADDLQSI,
	typeSXADDLSXDH,
	typeSXADDLSXFILT,
	typeSXADDLSXFILTER12,
	typeSXADDLSXFILTERS12,
	typeSXADDLSXMG,
	typeSXADDLSXMGS,
	typeSXADDLSXRULE,
	typeSXSRC,
	typeSXTBL,
	typeTABLESTYLES,
	typeTEXTOBJECT,
	typeTEXTPROPS,
	typeTHEME,
	typeUNKNOWNFRT,
	typeWINDOW,
	typeXFS,
	typeAnySubstream,
	typeChartSheetSubstream,
	typeABNFParenthesis,
	typeGlobalsSubstream,
	typeMacroSheetSubstream,
	typeWorkbookStreamObject,
	typeWorksheetSubstream,

	typeBiffStructure = 2000,
	typeBopPopCustomPiesIndices,
	typeIXFCellMulBlankSpecial,
	typeAddinUdf,
	typeAF12Criteria,
	typeAFDOper,
	typeAFDOperRk,
	typeAFDOperStr,
	typeBes,
	typeBiffAttribute,
	typeBookExt_Conditional11,
	typeBookExt_Conditional12,
	typeBuiltInStyle,
	typeCell,
	typeCellOffsetResender,
	typeCellRangeRef,
	typeCellRef,
	typeCellXF,
	typeCFColor,
	typeCFExNonCF12,
	typeCFExTemplateParams,
	typeCFMStateItem,
	typeCFMultistate,
	typeCFVO,
	typeCondFmtStructure,
	typeControlInfo,
	typeDropDownObjId,
	typeDXFALC,
	typeDXFBdr,
	typeDXFFntD,
	typeDXFId,
	typeDXFN,
	typeDXFN12,
	typeDXFN12List,
	typeDXFNum,
	typeDXFNumUsr,
	typeDXFPat,
	typeDXFProt,
	typeEnhancedProtection,
	typeExternDdeLinkNoOper,
	typeExternDocName,
	typeExternOleDdeLink,
	typeExtProp,
	typeExtRst,
	typeFactoidData,
	typeFeat11FdaAutoFilter,
	typeFeat11FieldDataItem,
	typeFeatFormulaErr2,
	typeFeatProtection,
	typeFeatSmartTag,
	typeFileOffset,
	typeFilePointer,
	typeFormatRun,
	typeFrtHeader,
	typeFrtHeaderOld,
	typeFrtRefHeader,
	typeFrtRefHeaderNoGrbit,
	typeFrtRefHeaderU,
	typeFtCblsData,
	typeFtCf,
	typeFtCmo,
	typeFtEdoData,
	typeFtGboData,
	typeFtLbsData,
	typeFtMacro,
	typeFtNts,
	typeFtPictFmla,
	typeFtPioGrbit,
	typeFtRboData,
	typeFtSbs,
	typeFullColorExt,
	typeGradStop,
	typeHorzBrk,
	typeISSTInf,
	typeLbsDropData,
	typeList12BlockLevel,
	typeList12DisplayName,
	typeList12TableStyleClientInfo,
	typeLongRGBA,
	typeMDir,
	typeMDXStrIndex,
	typeMOper,
	typeNoteRR,
	typeNoteSh,
	typeObjFmla,
	typeObjLinkFmla,
	typeParsedFormula,
	typePhRuns,
	typePhs,
	typePictFmlaEmbedInfo,
	typePictFmlaKey,
	typePtg,
	typeRevItab,
	typeRevLblName,
	typeRevNamePly,
	typeRgbExtra,
	typeRgce,
	typeRkRec,
	typeRPHSSub,
	typeRRD,
	typeRun,
	typeSDContainer,
	typeSecurityDescriptor,
	typeSerAr,
	typeSheetExtOptional,
	typeSheetId,
	typeSortCond12,
	typeSqRef,
	typeSqRefU,
	typeStxp,
	typeStyleXF,
	typeTableFeatureType,
	typeTxOLastRun,
	typeTxORuns,
	typeVertBrk,
	typeXFExtGradient,
	typeXFExtNoFRT,
	typeXFProp,
	typeXFPropBorder,
	typeXFPropColor,
	typeXFPropGradient,
	typeXFPropGradientStop,
	typeXFProps,
	typeXLUnicodeRichExtendedString,
	typeXORObfuscation,
	typeXTI,
	
	typeIMsoArray,
	typeMSOCR,
	typeMSOSHADECOLOR,
	typeAntiMoniker,
	typeVersion,
	typeCompositeMoniker,
	typeEncryptionHeader,
	typeEncryptionHeaderFlags,
	typeEncryptionVerifier,
	typeFactoidType,
	typeFileMoniker,
	typeHyperlinkMoniker,
	typeHyperlinkObject,
	typeItemMoniker,
	typeProperty,
	typePropertyBag,
	typePropertyBagStore,
	typeRC4CryptoAPIEncryptionHeader,
	typeRC4EncryptionHeader,
	typeURICreateFlags,
	typeURLMoniker,

	typeOfficeArtRecord = 3000,
	typeOfficeArtBStoreContainerFileBlock,
	typeOfficeArtCOLORREF,
	typeOfficeArtFOPTE,
	typeOfficeArtFRIT,
	typeOfficeArtIDCL,
	typeOfficeArtMetafileHeader,
	typeOfficeArtRecordHeader,
	typeOfficeArtRGFOPTE,
	typeOfficeArtBlip,
	typeOfficeArtBStoreContainer,
	typeOfficeArtClientAnchorChart,
	typeOfficeArtClientAnchorHF,
	typeOfficeArtClientAnchorSheet,
	typeOfficeArtColorMRUContainer,
	typeOfficeArtContainer,
	typeOfficeArtFDG,
	typeOfficeArtFDGGBlock,
	typeOfficeArtFOPT,
	typeOfficeArtFRITContainer,
	typeOfficeArtFSP,
	typeOfficeArtFSPGR,
	typeOfficeArtSplitMenuColorContainer,
	typeOfficeArtTertiaryFOPT,
	typeOfficeArtClientData,
	typeOfficeArtClientTextbox


};



}