// eshuo.c

#include <ansi.h>
inherit NPC;
inherit F_UNIQUE;

void create()
{
	set_name(HIY "鄂硕克哈" NOR, ({"eshuo keha", "eshuo", "keha"}));
	set("title", HIB"镶蓝旗旗主"NOR);
	set("gender", "男性");
	set("age", 36);
	set("str", 25);
	set("dex", 20);
	set("int", 28);
	set("con", 28);
	set("per", 20);

	set("combat_exp", 10000);
	set("score", 200);
	set("shen_type", 1);
	set("attitude", "peaceful");

	set_skill("unarmed", 30);
	set_skill("dodge", 30);
	set_skill("force", 30);
	set_skill("hunyuan-yiqi", 30);
	set_skill("shaolin-shenfa", 30);
	set_skill("finger", 30);
	set_skill("nianhua-zhi", 30);
	map_skill("force", "hunyuan-yiqi");
	map_skill("dodge", "shaolin-shenfa");
	map_skill("parry", "nianhua-zhi");
	map_skill("finger", "nianhua-zhi");
	prepare_skill("finger", "nianhua-zhi");

	set_temp("apply/attack", 50);
	set_temp("apply/defence", 50);
	set_temp("apply/armor", 30);
	set_temp("apply/damage", 35);

	set("qi", 1000);
	set("max_qi", 1000);
	set("jing", 600);
	set("max_jing", 600);
	set("neili", 2000);
	set("max_neili", 2000);
	set("jiali", 80);

	setup();
	carry_object(__DIR__"obj/chaofu")->wear();
	add_money("gold", 5);
}

