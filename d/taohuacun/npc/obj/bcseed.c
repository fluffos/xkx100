
inherit ITEM;

void create()
{
	set_name("白菜苗",({"baicai seed"}));
	set_weight(50);
	set("value", 100);
	if( clonep() )
                set_default_object(__FILE__);
        else {
                set("long", "一袋白菜苗。\n");
                set("unit", "袋");
        }
}

