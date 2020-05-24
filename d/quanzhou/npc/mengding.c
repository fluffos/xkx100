// mengding.c

inherit NPC;

void create()
{
	set_name("武馆门丁",({ "meng ding","ding" }) );
	set("gender", "男性" );
	set("age", 22);
	set("combat_exp", 7000);
	set("shen", 100);
	set("shen_type", 1);
	set("str", 30);
	set("dex", 30);
	set("con", 30);
	set("int", 30);
	set("attitude", "friendly");

	setup();
        carry_object("/clone/cloth/beixin")->wear();
}

