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
// File:      PhysicsList.cc
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


// USER//
#include "PhysicsList.hh"

// GEANT4 //
#include "G4EmStandardPhysics.hh"


PhysicsList::PhysicsList()
{
    RegisterPhysics(new G4EmStandardPhysics());
}

PhysicsList::~PhysicsList()
{;}

void PhysicsList::ConstructParticle()
{
    G4VModularPhysicsList::ConstructParticle();
}

void PhysicsList::ConstructProcess()
{
    G4VModularPhysicsList::ConstructProcess();
}


void PhysicsList::SetCuts()
{
    SetCutValue(defaultCutValue, "gamma");
    SetCutValue(defaultCutValue, "e-");
    SetCutValue(defaultCutValue, "e+");
}

