
#include <ansi.h>
#include <armor.h>

inherit CLOTH;

void create()
{
        set_name( "上等烟草", ({ "shangdeng yancao", "yancao" }) );
        set_weight(800);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "包");
                set("value", 1000);
                set("material", "leather");           
        }
        setup();
}

