#pragma once

#include "BiffRecord.h"
#include <Logic/Biff_structures/LongRGB.h>

namespace XLS
{;


// Logical representation of Palette record in BIFF8
class Palette: public BiffRecord
{
	BIFF_RECORD_DEFINE_TYPE_INFO(Palette)
	BASE_OBJECT_DEFINE_CLASS_NAME(Palette)
public:
	Palette();
	Palette(const unsigned __int16 ccv_init);

	BaseObjectPtr clone();

	void writeFields(CFRecord& record);
	void readFields(CFRecord& record);
private:
	BiffStructurePtrVector rgColor;
	unsigned __int16 ccv;
public:
	BO_ATTRIB_MARKUP_BEGIN
		BO_ATTRIB_MARKUP_VECTOR_COMPLEX(rgColor, LongRGB)
	BO_ATTRIB_MARKUP_END

};

} // namespace XLS
