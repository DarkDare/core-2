#pragma once

#include <Logic/Biff_records/BiffRecord.h>
#include <Logic/Biff_structures/BiffString.h>
#include "AFDOperStr.h"

namespace XLS
{;

class AFDOper: public BiffStructure
{	
	BASE_OBJECT_DEFINE_CLASS_NAME(AFDOper)
public:
	BiffStructurePtr clone();

	AFDOper();
	AFDOper(bool bAutoFilter);
	~AFDOper();

	//virtual void setXMLAttributes(MSXML2::IXMLDOMElementPtr xml_tag);
	//virtual void getXMLAttributes(MSXML2::IXMLDOMElementPtr xml_tag);
	virtual void load(CFRecord& record);
	virtual void store(CFRecord& record);

	BIFF_BYTE vt;
	BIFF_BYTE grbitSign;
	AFDOperStr vtValue;

public:
	bool m_bAutoFilter;
};

} // namespace XLS