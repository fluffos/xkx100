// smith.c

inherit NPC;
inherit F_DEALER;

void create()
{
	set_name("铁匠", ({ "tiejiang", "smith" }));
	set("title", "铁匠铺老板");
	set("shen_type", 1);

	set("gender", "男性" );
	set("age", 33);
	set("long", "铁匠正用铁钳夹住一块红热的铁块放进炉中。\n");

	set("combat_exp", 400);
	set("attitude", "friendly");
	set("vendor_goods",({
		"/d/5lt/npc/obj/gangkui",
		"/d/5lt/npc/obj/tiejia",
	}));

	setup();

	carry_object("/clone/misc/cloth")->wear();
}

void init()
{
	add_action("do_list", "list");
	add_action("do_buy", "buy");
}