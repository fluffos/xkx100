// heiyi.c
// Last Modified by winder on Sep. 27 2001

#include <armor.h>
inherit CLOTH;

void create()
{
        set_name("黑色长衫", ({ "chang shan", "cloth" }) );
        set_weight(2000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "件");
                set("material", "cloth");
                set("armor_prop/armor", 1);
        }
        setup();
}

