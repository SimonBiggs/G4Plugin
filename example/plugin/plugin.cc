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
// File:      plugin.cc 
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


#include "globals.hh"
#include "G4Box.hh"
#include "G4LogicalVolume.hh"
#include "G4PVPlacement.hh"
#include "G4NistManager.hh"
#include "G4Material.hh"

class G4VPhysicalVolume;

extern "C" G4VPhysicalVolume* create() {

     G4NistManager * nist_manager = G4NistManager::Instance();
     G4Material * air = nist_manager->FindOrBuildMaterial("G4_AIR");
     G4Material * water = nist_manager->FindOrBuildMaterial("G4_WATER");

     G4Box * world_solid = new G4Box("world_solid", 50*cm, 50*cm, 50*cm);
     G4LogicalVolume * world_logical = new G4LogicalVolume(world_solid, air,"world_logical",0,0,0);
     G4VPhysicalVolume * world_physical = new G4PVPlacement(0, G4ThreeVector(), world_logical,
                                                            "world_physical", 0, false, 0); 
     G4Box * daughter_solid = new G4Box("daughter_solid", 20*cm, 10*cm, 10*cm);
     G4LogicalVolume * daughter_logical = new G4LogicalVolume(daughter_solid, water,"daughter_logical",0,0,0);
     G4VPhysicalVolume * daughter_physical = new G4PVPlacement(0, G4ThreeVector(), daughter_logical,
                                                            "daugther_physical", world_logical, false, 0); 

     return world_physical;
}

extern "C" void destroy(G4VPhysicalVolume* vol) {
    delete vol;
}

