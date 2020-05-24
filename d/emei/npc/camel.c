// camel.c

#include <command.h>
#include <dbase.h>
#include <origin.h>

inherit NPC;

void create()
{
	set_name("白骆驼", ({ "camel" }));
	set("long","一匹白骆驼。\n");
	set("race", "走畜");
	set("age", 5);
	set("attitude","heroism");
	set("str", 30);
	set("dex", 35);
	set("con", 40);
	set("int", 10);
	set("shen", 1);
	set("combat_exp", 2000);
	setup();
}
