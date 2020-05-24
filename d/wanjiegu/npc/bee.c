// bee.c
inherit NPC;

void create()
{
        set_name("蜜蜂", ({ "bee" }) );
	set("race", "昆虫");
	set("subrace", "飞虫");
        set("age", 1);
        set("long", "一只疯狂的杀人蜂。\n");

        set_skill("dodge", 50);
        set("combat_exp", 500);
        set("bellicosity", 3000 );

        setup();
}
