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
// File:      G4Plugin.hh 
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


// https://github.com/christopherpoole/cppplugin
#include "Plugin.hh"

// GEANT4 //
#include "globals.hh"


template<class T>
class G4Plugin : public Plugin<T>
{
  public:
    G4Plugin(const char * shared_object,
             const char * entry_symbol="create",
             const char * exit_symbol="destroy")
    try : Plugin<T>(shared_object, entry_symbol, exit_symbol)
    {;}   
    catch (PluginException &exception) {
        G4Exception("G4Plugin::G4Plugin", "Plugin not loaded.",
                    FatalException, exception.what());
    }        
};

