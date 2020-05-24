// Room: /d/gaochang/zoulangw.c
// Last Modified by Winder on Jul. 15 2000

inherit ROOM;
string look_writing();

void create()
{
	set("short", "走廊");
	set("long", @LONG
这里是殿堂走廊。房顶一侧支在南面的高墙上，另一侧则与北边殿
堂的屋顶相连。彩梁画栋，抬眼望去，连顶棚也用彩漆绘满了各种飞天
的图形，每幅画似乎都在诉说一个娓娓动人的佛经故事。南边墙上题着
一个字(writing)。
LONG
	);

	set("exits", ([
		"southeast" : __DIR__"wroom3",
		"northeast" : __DIR__"zoulangc",
	]));
	set("item_desc",([
		"writing"		:	(: look_writing :),
	]));
	set("no_clean_up", 0);
	setup();
}

string look_writing()
{
	return
	"\n"
"              仙仙仙仙仙仙仙仙仙仙仙仙仙仙仙仙仙\n"
"              仙仙仙仙  仙仙仙仙仙    仙仙仙仙仙\n"
"              仙仙仙仙  仙仙仙仙仙  仙仙仙仙仙仙\n"
"              仙仙仙    仙仙仙仙仙  仙仙仙仙仙仙\n"
"              仙仙    仙仙仙仙仙仙  仙仙仙仙仙仙\n"
"              仙    仙  仙仙仙仙仙  仙仙仙仙仙仙\n"
"              仙仙仙仙  仙仙  仙仙  仙仙仙  仙仙\n"
"              仙仙仙仙  仙仙  仙仙  仙仙仙  仙仙\n"
"              仙仙仙仙  仙仙  仙仙  仙仙仙  仙仙\n"
"              仙仙仙仙  仙仙  仙仙  仙仙仙  仙仙\n"
"              仙仙仙仙  仙仙                仙仙\n"
"              仙仙仙    仙仙  仙仙仙仙仙仙  仙仙\n"
"              仙仙仙仙仙仙仙仙仙仙仙仙仙仙仙仙仙\n"
"              仙仙仙仙仙仙仙仙仙仙仙仙仙仙仙仙仙\n";
}

void init()
{
	add_action("do_study", "yanxi");
}


int do_study(string arg)
{
	object me = this_player();
	int cost=10;	

	if ( !arg && ( arg != "qiang" ) && ( arg != "qiangbi" ) )
		return notify_fail("什么？\n");

	if ( (int)me->query_skill("literate", 1) < 1)
		return notify_fail("你是个文盲，先学点文化(literate)吧。\n");

	if((int)me->query("jing") < 30)
		return notify_fail("你现在精神无法集中！\n");

	me->receive_damage("jing", 10);

	message_vision("$N正专心研读墙壁上的古怪图形。\n", me);

	if ( (int)me->query_skill("medicine", 1) < 100)
	{
	      if ((int)me->query("jing")>cost)
		{me->improve_skill("medicine", (int)(me->query("int")/4));
		 write("你对着墙壁琢磨了一回儿，似乎对济世之术有点心得。\n");
		 me->set_temp("stone_learned",1);
		 return 1;
		}
		else
	     {
		cost=me->query("jing");
		write("你现在过于疲倦，无法专心下来研读济世之术。\n");
	     } 
		 
	}

	if ( !me->query_temp("stone_learned") )
	{
		write("你对着墙壁琢磨了一回儿，发现上面所说的太过浅显，对你来说已毫无意义了。\n");
	}
	return 1;
}

