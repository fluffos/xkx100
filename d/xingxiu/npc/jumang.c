// Room: /d/xingxiu/npc/jumang.c
// Last Modified by Winder on Apr. 25 2001

inherit NPC;

void create()
{
	set_name("巨蟒", ({ "ju mang", "mang" }));
	set("race", "爬蛇");
	set("age", 200);
	set("long", "一条庞大无比, 色彩斑斓的巨蟒。 浑身发出阵阵强烈的腥臭味。\n");
	set("attitude", "peaceful");
	set("str", 70);
	set("con", 50);
	set("max_qi", 800);
	set("combat_exp", 120000);
	set_temp("apply/attack", 50);
	set_temp("apply/armor", 50);
	setup();
}

init()
{
	object ob;
	mapping myfam;
	::init();
	if (interactive(ob = this_player()) && !is_fighting())
	{
		myfam = (mapping)ob->query("family");
		if ((!myfam || myfam["family_name"] != "星宿派") &&
			(!wizardp(ob)))
		{
			remove_call_out("do_killing");
			call_out("do_killing",1,ob);
		}
	}
}
