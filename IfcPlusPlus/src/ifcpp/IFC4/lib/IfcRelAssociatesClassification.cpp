/* Code generated by IfcQuery EXPRESS generator, www.ifcquery.com */
#include <sstream>
#include <limits>

#include "ifcpp/model/IfcPPException.h"
#include "ifcpp/model/IfcPPAttributeObject.h"
#include "ifcpp/model/IfcPPGuid.h"
#include "ifcpp/reader/ReaderUtil.h"
#include "ifcpp/writer/WriterUtil.h"
#include "ifcpp/IFC4/include/IfcClassification.h"
#include "ifcpp/IFC4/include/IfcClassificationReference.h"
#include "ifcpp/IFC4/include/IfcClassificationSelect.h"
#include "ifcpp/IFC4/include/IfcDefinitionSelect.h"
#include "ifcpp/IFC4/include/IfcGloballyUniqueId.h"
#include "ifcpp/IFC4/include/IfcLabel.h"
#include "ifcpp/IFC4/include/IfcOwnerHistory.h"
#include "ifcpp/IFC4/include/IfcRelAssociatesClassification.h"
#include "ifcpp/IFC4/include/IfcText.h"

// ENTITY IfcRelAssociatesClassification 
IfcRelAssociatesClassification::IfcRelAssociatesClassification() {}
IfcRelAssociatesClassification::IfcRelAssociatesClassification( int id ) { m_id = id; }
IfcRelAssociatesClassification::~IfcRelAssociatesClassification() {}
shared_ptr<IfcPPObject> IfcRelAssociatesClassification::getDeepCopy( IfcPPCopyOptions& options )
{
	shared_ptr<IfcRelAssociatesClassification> copy_self( new IfcRelAssociatesClassification() );
	if( m_GlobalId )
	{
		if( options.create_new_IfcGloballyUniqueId ) { copy_self->m_GlobalId = shared_ptr<IfcGloballyUniqueId>(new IfcGloballyUniqueId( createGUID32_wstr().c_str() ) ); }
		else { copy_self->m_GlobalId = dynamic_pointer_cast<IfcGloballyUniqueId>( m_GlobalId->getDeepCopy(options) ); }
	}
	if( m_OwnerHistory )
	{
		if( options.shallow_copy_IfcOwnerHistory ) { copy_self->m_OwnerHistory = m_OwnerHistory; }
		else { copy_self->m_OwnerHistory = dynamic_pointer_cast<IfcOwnerHistory>( m_OwnerHistory->getDeepCopy(options) ); }
	}
	if( m_Name ) { copy_self->m_Name = dynamic_pointer_cast<IfcLabel>( m_Name->getDeepCopy(options) ); }
	if( m_Description ) { copy_self->m_Description = dynamic_pointer_cast<IfcText>( m_Description->getDeepCopy(options) ); }
	for( size_t ii=0; ii<m_RelatedObjects.size(); ++ii )
	{
		auto item_ii = m_RelatedObjects[ii];
		if( item_ii )
		{
			copy_self->m_RelatedObjects.push_back( dynamic_pointer_cast<IfcDefinitionSelect>(item_ii->getDeepCopy(options) ) );
		}
	}
	if( m_RelatingClassification ) { copy_self->m_RelatingClassification = dynamic_pointer_cast<IfcClassificationSelect>( m_RelatingClassification->getDeepCopy(options) ); }
	return copy_self;
}
void IfcRelAssociatesClassification::getStepLine( std::stringstream& stream ) const
{
	stream << "#" << m_id << "= IFCRELASSOCIATESCLASSIFICATION" << "(";
	if( m_GlobalId ) { m_GlobalId->getStepParameter( stream ); } else { stream << "*"; }
	stream << ",";
	if( m_OwnerHistory ) { stream << "#" << m_OwnerHistory->m_id; } else { stream << "*"; }
	stream << ",";
	if( m_Name ) { m_Name->getStepParameter( stream ); } else { stream << "*"; }
	stream << ",";
	if( m_Description ) { m_Description->getStepParameter( stream ); } else { stream << "*"; }
	stream << ",";
	stream << "(";
	for( size_t ii = 0; ii < m_RelatedObjects.size(); ++ii )
	{
		if( ii > 0 )
		{
			stream << ",";
		}
		const shared_ptr<IfcDefinitionSelect>& type_object = m_RelatedObjects[ii];
		if( type_object )
		{
			type_object->getStepParameter( stream, true );
		}
		else
		{
			stream << "$";
		}
	}
	stream << ")";
	stream << ",";
	if( m_RelatingClassification ) { m_RelatingClassification->getStepParameter( stream, true ); } else { stream << "$" ; }
	stream << ");";
}
void IfcRelAssociatesClassification::getStepParameter( std::stringstream& stream, bool ) const { stream << "#" << m_id; }
const std::wstring IfcRelAssociatesClassification::toString() const { return L"IfcRelAssociatesClassification"; }
void IfcRelAssociatesClassification::readStepArguments( const std::vector<std::wstring>& args, const std::map<int,shared_ptr<IfcPPEntity> >& map )
{
	const size_t num_args = args.size();
	if( num_args != 6 ){ std::stringstream err; err << "Wrong parameter count for entity IfcRelAssociatesClassification, expecting 6, having " << num_args << ". Entity ID: " << m_id << std::endl; throw IfcPPException( err.str().c_str() ); }
	m_GlobalId = IfcGloballyUniqueId::createObjectFromSTEP( args[0], map );
	readEntityReference( args[1], m_OwnerHistory, map );
	m_Name = IfcLabel::createObjectFromSTEP( args[2], map );
	m_Description = IfcText::createObjectFromSTEP( args[3], map );
	readSelectList( args[4], m_RelatedObjects, map );
	m_RelatingClassification = IfcClassificationSelect::createObjectFromSTEP( args[5], map );
}
void IfcRelAssociatesClassification::getAttributes( std::vector<std::pair<std::string, shared_ptr<IfcPPObject> > >& vec_attributes )
{
	IfcRelAssociates::getAttributes( vec_attributes );
	vec_attributes.push_back( std::make_pair( "RelatingClassification", m_RelatingClassification ) );
}
void IfcRelAssociatesClassification::getAttributesInverse( std::vector<std::pair<std::string, shared_ptr<IfcPPObject> > >& vec_attributes_inverse )
{
	IfcRelAssociates::getAttributesInverse( vec_attributes_inverse );
}
void IfcRelAssociatesClassification::setInverseCounterparts( shared_ptr<IfcPPEntity> ptr_self_entity )
{
	IfcRelAssociates::setInverseCounterparts( ptr_self_entity );
	shared_ptr<IfcRelAssociatesClassification> ptr_self = dynamic_pointer_cast<IfcRelAssociatesClassification>( ptr_self_entity );
	if( !ptr_self ) { throw IfcPPException( "IfcRelAssociatesClassification::setInverseCounterparts: type mismatch" ); }
	shared_ptr<IfcClassification>  RelatingClassification_IfcClassification = dynamic_pointer_cast<IfcClassification>( m_RelatingClassification );
	if( RelatingClassification_IfcClassification )
	{
		RelatingClassification_IfcClassification->m_ClassificationForObjects_inverse.push_back( ptr_self );
	}
	shared_ptr<IfcClassificationReference>  RelatingClassification_IfcClassificationReference = dynamic_pointer_cast<IfcClassificationReference>( m_RelatingClassification );
	if( RelatingClassification_IfcClassificationReference )
	{
		RelatingClassification_IfcClassificationReference->m_ClassificationRefForObjects_inverse.push_back( ptr_self );
	}
}
void IfcRelAssociatesClassification::unlinkFromInverseCounterparts()
{
	IfcRelAssociates::unlinkFromInverseCounterparts();
	shared_ptr<IfcClassification>  RelatingClassification_IfcClassification = dynamic_pointer_cast<IfcClassification>( m_RelatingClassification );
	if( RelatingClassification_IfcClassification )
	{
		std::vector<weak_ptr<IfcRelAssociatesClassification> >& ClassificationForObjects_inverse = RelatingClassification_IfcClassification->m_ClassificationForObjects_inverse;
		for( auto it_ClassificationForObjects_inverse = ClassificationForObjects_inverse.begin(); it_ClassificationForObjects_inverse != ClassificationForObjects_inverse.end(); )
		{
			shared_ptr<IfcRelAssociatesClassification> self_candidate( *it_ClassificationForObjects_inverse );
			if( self_candidate.get() == this )
			{
				it_ClassificationForObjects_inverse= ClassificationForObjects_inverse.erase( it_ClassificationForObjects_inverse );
			}
			else
			{
				++it_ClassificationForObjects_inverse;
			}
		}
	}
	shared_ptr<IfcClassificationReference>  RelatingClassification_IfcClassificationReference = dynamic_pointer_cast<IfcClassificationReference>( m_RelatingClassification );
	if( RelatingClassification_IfcClassificationReference )
	{
		std::vector<weak_ptr<IfcRelAssociatesClassification> >& ClassificationRefForObjects_inverse = RelatingClassification_IfcClassificationReference->m_ClassificationRefForObjects_inverse;
		for( auto it_ClassificationRefForObjects_inverse = ClassificationRefForObjects_inverse.begin(); it_ClassificationRefForObjects_inverse != ClassificationRefForObjects_inverse.end(); )
		{
			shared_ptr<IfcRelAssociatesClassification> self_candidate( *it_ClassificationRefForObjects_inverse );
			if( self_candidate.get() == this )
			{
				it_ClassificationRefForObjects_inverse= ClassificationRefForObjects_inverse.erase( it_ClassificationRefForObjects_inverse );
			}
			else
			{
				++it_ClassificationRefForObjects_inverse;
			}
		}
	}
}