/*
This file is part of Bohrium and copyright (c) 2012 the Bohrium
team <http://www.bh107.org>.

Bohrium is free software: you can redistribute it and/or modify
it under the terms of the GNU Lesser General Public License as
published by the Free Software Foundation, either version 3
of the License, or (at your option) any later version.

Bohrium is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the
GNU Lesser General Public License along with Bohrium.

If not, see <http://www.gnu.org/licenses/>.
*/
#include <stdio.h>
#include "component_interface.h"
#include "expander.hpp"

//
// Components
//

static bh_component myself;         // Myself
static bh_component_iface *child;   // My child

static bohrium::filter::composite::Expander* expander = NULL;

//
// Component interface init/execute/shutdown
//

bh_error bh_filter_composite_expansion_init(const char* name)
{
    bh_error err;
    if ((err = bh_component_init(&myself, name)) != BH_SUCCESS) {
        return err;
    }

    if (myself.nchildren != 1) {    // For now, we have one child exactly
        fprintf(stderr, "[validate-FILTER] Unexpected number of children, must be 1");
        return BH_ERROR;
    }
    
    child = &myself.children[0];    // Let us initiate the child.
    if ((err = child->init(child->name)) != 0) {
        return err;
    }

    expander = new bohrium::filter::composite::Expander();

    return BH_SUCCESS;
}

bh_error bh_filter_composite_expansion_shutdown(void)
{
    bh_error err = child->shutdown();
    bh_component_destroy(&myself);

    delete expander;
    expander = NULL;

    return err;
}

bh_error bh_filter_composite_expansion_execute(bh_ir* bhir)
{
    expander->expand(*bhir);
    return child->execute(bhir); // Execute the filtered bhir
}

bh_error bh_filter_composite_expansion_extmethod(const char *name, bh_opcode opcode)
{
    return child->extmethod(name, opcode);
}

