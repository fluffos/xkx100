// heisuo.c  黑索
#include <weapon.h>
inherit WHIP;

void create()
{
	set_name("黑索", ({ "heisuo", "bian" }));
	set_weight(500);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("unit", "根");
		set("long", "这是一根长索，通体黝黑无光，舞动之时瞧不见半点影子。\n");
		set("value", 100);
		set("material", "leather");
		set("wield_msg", "$N「唰」的一声抖出一条$n握在手中。\n");
		set("unwield_msg", "$N将手中的$n卷回腰间。\n");
	}
	init_whip(80);
	setup();
}
