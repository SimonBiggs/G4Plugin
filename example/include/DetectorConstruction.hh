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
// File:      DetectorConstruction.hh 
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


#ifndef DetectorConstruction_H
#define DetectorConstruction_H 1

// PLUGIN //
#include "G4Plugin.hh"

// GEANT4 //
#include "G4VUserDetectorConstruction.hh"
#include "G4VPhysicalVolume.hh"


class DetectorConstruction : public G4VUserDetectorConstruction
{
  public:
    DetectorConstruction();
    ~DetectorConstruction();

    G4VPhysicalVolume* Construct();


  private:
    G4VPhysicalVolume* world_physical;

    // PLUGIN
    G4Plugin<G4VPhysicalVolume> * plugin;

};
#endif

