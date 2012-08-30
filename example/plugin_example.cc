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
// File:      plugin_example.cc 
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
#include "DetectorConstruction.hh"
#include "PhysicsList.hh"
#include "PrimaryGeneratorAction.hh"

// GEANT4 //
#include "G4RunManager.hh"
#include "G4UImanager.hh"
#include "G4UIterminal.hh"
#include "G4UItcsh.hh"
#include "G4VisExecutive.hh"
#include "G4UIExecutive.hh"

int main(int argc,char** argv)
{
    G4RunManager* run_manager = new G4RunManager;

    G4VUserDetectorConstruction* detector_construction = new DetectorConstruction;
    run_manager->SetUserInitialization(detector_construction);

    G4VUserPhysicsList* physics_list = new PhysicsList;
    run_manager->SetUserInitialization(physics_list);

    G4VUserPrimaryGeneratorAction* primary_generator = new PrimaryGeneratorAction;
    run_manager->SetUserAction(primary_generator);

    run_manager->Initialize();
    
    G4VisManager* vis_manager = new G4VisExecutive;
    vis_manager->Initialize();

    G4UImanager* UImanager = G4UImanager::GetUIpointer();

    if (argc!=1)   // batch mode
    {
        G4String command = "/control/execute ";
        G4String fileName = argv[1];
        UImanager->ApplyCommand(command+fileName);
    }
    else
    {  // interactive mode : define UI session
        G4UIExecutive* ui = new G4UIExecutive(argc, argv);
        UImanager->ApplyCommand("/control/execute macros/vis.mac");
        if (ui->IsGUI())
            UImanager->ApplyCommand("/control/execute macros/gui.mac");
        ui->SessionStart();
        delete ui;
    }

    delete vis_manager;
    delete run_manager;

    return 0;
}


