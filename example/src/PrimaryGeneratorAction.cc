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
// File:      PrimaryGeneratorAction.cc
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

 
// USER //
#include "PrimaryGeneratorAction.hh"

// GEANT4 //
#include "globals.hh"

#include "G4Event.hh"
#include "G4GeneralParticleSource.hh"
#include "G4ParticleTable.hh"
#include "G4ParticleDefinition.hh"


PrimaryGeneratorAction::PrimaryGeneratorAction()
{
    particle_gun = new G4GeneralParticleSource();

    G4ParticleTable* particle_table = G4ParticleTable::GetParticleTable();
    G4ParticleDefinition* particle = particle_table->FindParticle("geantino");
  
    particle_gun->SetParticleDefinition(particle);
}

PrimaryGeneratorAction::~PrimaryGeneratorAction()
{
    delete particle_gun;
}

void PrimaryGeneratorAction::GeneratePrimaries(G4Event* event)
{
    particle_gun->GeneratePrimaryVertex(event);
}


