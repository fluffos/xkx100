#include <ansi.h>
inherit ITEM;

void create()
{
	set_name(HIY "獐腿肉" NOR,({"zhangrou"}));
	set_weight(300);
	if( clonep() )
                set_default_object(__FILE__);
        else {
                set("long", "一大块獐腿肉。\n");
                set("unit", "块");
        }
}