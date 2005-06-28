#ifndef FWCORESERVICES_EVENTSETUPRECORDDATAGETTER_H
#define FWCORESERVICES_EVENTSETUPRECORDDATAGETTER_H
// -*- C++ -*-
//
// Package:     FWCoreServices
// Class  :     EventSetupRecordDataGetter
// 
/**\class EventSetupRecordDataGetter EventSetupRecordDataGetter.h FWCore/FWCoreServices/interface/EventSetupRecordDataGetter.h

 Description: Can be configured to 'get' any Data in any EventSetup Record.  Primarily used for testing.

 Usage:
    <usage>

*/
//
// Original Author:  Chris Jones
//         Created:  Tue Jun 28 13:45:06 EDT 2005
// $Id$
//

// system include files
#include <map>
#include <vector>
#include <boost/shared_ptr.hpp>

// user include files
#include "FWCore/CoreFramework/interface/CoreFrameworkfwd.h"
#include "FWCore/CoreFramework/interface/EDAnalyzer.h"
#include "FWCore/ParameterSet/interface/ParameterSet.h"

#include "FWCore/CoreFramework/interface/EventSetupRecord.h"
#include "FWCore/CoreFramework/interface/Timestamp.h"

// forward declarations
namespace edm {
   class EventSetupRecordDataGetter : public edm::EDAnalyzer {
public:
      explicit EventSetupRecordDataGetter( const edm::ParameterSet& );
      ~EventSetupRecordDataGetter();
      
      
      virtual void analyze( const edm::Event&, const edm::EventSetup& );
private:
         // ----------member data ---------------------------
      ParameterSet pSet_;
      
      typedef std::map<edm::eventsetup::EventSetupRecordKey, std::vector<edm::eventsetup::DataKey> > RecordToDataKeys;
      RecordToDataKeys recordToDataKeys_;
      //NOTE: forced to use shared_ptr<Timestamp> instead of just Timestamp since insertion into the map
      //  requires the presence of a default constructor which Timestamp does not have
      std::map<eventsetup::EventSetupRecordKey, boost::shared_ptr<edm::Timestamp> > recordToTimestamp_;
      bool verbose_;
   };
}


#endif /* FWCORESERVICES_EVENTSETUPRECORDDATAGETTER_H */
