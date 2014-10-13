#pragma once

#include "BiffStructure.h"
#include "CellRef.h"
#include <stack>
#include <queue>

namespace XLS
{;

class CFRecord;

class Ptg;
typedef	boost::shared_ptr<Ptg> PtgPtr;
typedef std::stack<std::wstring> AssemblerStack;
typedef std::vector<PtgPtr> PtgVector;
typedef std::stack<PtgPtr> PtgStack;
typedef std::vector<PtgPtr>::const_iterator PtgVectorIterator;

typedef std::queue<PtgPtr> PtgQueue;


class Ptg : public BiffStructure // still abstract
{
public:
	Ptg();
	Ptg(const unsigned __int16 ptg_id_init);

	virtual void load(CFRecord& record);
	virtual void store(CFRecord& record);

	virtual void loadFields(CFRecord& record) {};
	virtual void storeFields(CFRecord& record) {};



	virtual const unsigned __int16 getPtgId() const;// = 0;
	const size_t getOffsetInRecord() const;
	const size_t getSizeOfStruct() const;

	virtual void assemble(AssemblerStack& ptg_stack, PtgQueue& extra_data, BiffStructurePtr & parent);

protected:
	void addFuncWrapper(AssemblerStack& ptg_stack, const std::wstring& func_name);

private:
	nullable<unsigned __int16> ptg_id;
	nullable<size_t> offset_in_record;
	nullable<size_t> size_of_struct;
};


} // namespace XLS
