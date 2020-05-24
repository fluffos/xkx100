// banjiu.c

inherit NPC;

void create()
{
	set_name("斑鸠",({ "ban jiu", "bird" }) );
	set("race", "飞禽");
        set("gender", "雄性" );
        set("age", 13);
        set_temp("apply/defense", 10);
        set("combat_exp", 100);
        set("attitude", "peaceful");
        setup();
}
