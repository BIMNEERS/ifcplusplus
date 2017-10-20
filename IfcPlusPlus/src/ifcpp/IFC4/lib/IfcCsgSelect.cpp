/* Code generated by IfcQuery EXPRESS generator, www.ifcquery.com */
#include <map>
#include "ifcpp/model/IfcPPBasicTypes.h"
#include "ifcpp/model/IfcPPException.h"
#include "ifcpp/reader/ReaderUtil.h"
#include "ifcpp/IFC4/include/IfcCsgSelect.h"

// TYPE IfcCsgSelect = SELECT	(IfcBooleanResult	,IfcCsgPrimitive3D);
shared_ptr<IfcCsgSelect> IfcCsgSelect::createObjectFromSTEP( const std::wstring& arg, const std::map<int,shared_ptr<IfcPPEntity> >& map )
{
	if( arg.size() == 0 ){ return shared_ptr<IfcCsgSelect>(); }
	if( arg.compare(L"$")==0 )
	{
		return shared_ptr<IfcCsgSelect>();
	}
	if( arg.compare(L"*")==0 )
	{
		return shared_ptr<IfcCsgSelect>();
	}
	shared_ptr<IfcCsgSelect> result_object;
	readSelectType( arg, result_object, map );
	return result_object;
}