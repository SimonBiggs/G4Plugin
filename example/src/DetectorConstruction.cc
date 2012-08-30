//////////////////////////////////////////////////////////////////////////
// License & Copyright
// ===================
// 
// Copyright 2011 Christopher M Poole
// 
// This program is free software: you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.
// 
// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.
// 
// You should have received a copy of the GNU General Public License
// along with this program.  If not, see <http://www.gnu.org/licenses/>.
// 
// 
// GEANT4 Binary Plugin Example 
// ============================
// 
// File:      DetectorConstruction.cc
// 
// Author:    Christopher M Poole
// Email:     mail@christopherpoole.net
// Date:      31st December, 2011
//
// 
// Change Log
// ==========
// 
// 
//////////////////////////////////////////////////////////////////////////


#include <iostream>

// USER //
#include "DetectorConstruction.hh"

// GEANT4 //
#include "globals.hh"


DetectorConstruction::DetectorConstruction()
{
/*    try { 
        plugin = new Plugin<G4VPhysicalVolume>("plugin/build/libplugin.so", "create", "destroy");
    }
    catch (PluginException &e) {
        G4Exception("DetectorConstruction::DetectorConstruction",
                    "NoPluginFound", FatalException, e.what());
    }
*/
    plugin = new G4Plugin<G4VPhysicalVolume>("plugin/build/libplugin.so");
}

DetectorConstruction::~DetectorConstruction()
{
    if (world_physical) {
        G4cout << "Closing plugin... " << std::flush;
        plugin->Unload();
        G4cout << "done." << G4endl;
    }
}

G4VPhysicalVolume* DetectorConstruction::Construct()
{
    G4cout << "Opening plugin... " << std::flush;
    world_physical = plugin->Load();
    G4cout << "done." << G4endl;

    if (world_physical) {
        G4cout << "loaded" << G4endl;
    } else {
        G4cout << "not loaded" << G4endl;
    }

    return world_physical;
}

