// xifu.c
// Last Modifyed by Ahda on Jan. 4 2002

#include <armor.h>
inherit CLOTH;

void create()
{
        set_name("西洋服", ({ "cloth" }) );
        set_weight(3000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "件");
                set("material", "cloth");
                set("armor_prop/armor", 1);
        }
        setup();
}

