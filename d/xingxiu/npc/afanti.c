// npc: /d/xingxiu/npc/afanti.c
// Jay 3/26/96

inherit NPC;

//string ask_me();

void create()
{
        set_name("阿凡提", ({ "afanti" }) );
        set("gender", "男性" );
        set("age", 48);
        set("long", 
            "他头上包着头巾，长着向上翘的八字胡，最喜欢捉弄巴依、帮助穷人。他常"
            "给别人出谜语。\n");
        set("str", 25);
        set("dex", 20);
        set("con", 17);
        set("int", 15);
        set("shen_type", 1);

        set_skill("unarmed", 30);
        set_skill("dodge", 25);
        set_temp("apply/attack", 25);
        set_temp("apply/defense", 25);
        set("combat_exp", 2500);

        set("attitude", "peaceful");
        set("inquiry", ([
            "name" : "我就是纳苏尔的阿凡提。",
            "here" : "这里可真是个好地方。",
            "纳苏尔" : "是我出生的地方。",
            "谜语" : "你帮我找到小毛驴，我就给你出谜语。",
            "巴依" : "他把我关在这里，有吃有喝，我就不走了。巴依是个坏蛋，愿胡大惩罚他。",
            "毛驴" : "我的小毛驴在我到沙漠里骗巴依种金子时走丢了。",
            "驴" : "我的小毛驴在我到沙漠里骗巴依种金子时走丢了。",
            "小毛驴" : "我的小毛驴在我到沙漠里骗巴依种金子时走丢了。",
            "卷帘格" : "卷帘格指谜底各字顺序颠倒过来和谜面相扣。",
            "胡大" : "就是真主。又名安拉或阿拉。",
            "真主" : "真主至大，万物非主，唯有真主。穆罕默德是真主的使者。",
       ]) );

        setup();
        set("chat_chance", 10);
        set("chat_msg", ({
             "阿凡提叹了口气：嗨，可惜我的驴。\n",
        }) );
        carry_object(__DIR__"obj/wcloth")->wear();
        carry_object(__DIR__"obj/dongbula");
}

void init()
{
        ::init();
        add_action("do_answer","answer");
}

int accept_object(object who, object ob)
{
//     if((string)ob->query("name")=="小毛驴") {
     if((string)ob->query("id")=="mao lv") {
           remove_call_out("destroying");
           call_out("destroying", 1, this_object(), ob);

           if( who->query_temp("marks/谜") ) {
                 write("阿凡提笑了笑，说：你先把上个谜猜出来再说。\n");
//               destruct(ob);
                 return 1;
           }
           else {
                 write("阿凡提笑得嘴都合不上了，说：多谢这位" + 
                       RANK_D->query_respect(who) +
                       "的帮助，咱们猜个谜语吧：\n");
                 switch(random(20)) {
                   case 0:
                       write("妇女读物。(打一本泥潭玩家名)\n");
                       who->set_temp("marks/谜", 1);
                       break;
                   case 1:
                       write("雪在烧，雪在烧。(打一本泥潭玩家名)\n");
                       who->set_temp("marks/谜", 2);
                       break;
                   case 2:
                       write("邓小平之后。(打一本泥潭NPC名)\n");
                       who->set_temp("marks/谜", 3);
                       break;
                   case 3:
                       write("御用经典。(打一本泥潭玩家名)\n");
                       who->set_temp("marks/谜", 4);
                       break;
                   case 4:
                       write("打谷场上的NPC。(打一本泥潭玩家名)\n");
                       who->set_temp("marks/谜", 5);
                       break;
                   case 5:
		       write("巴黎习语。(打一本泥潭技能名，卷帘格)\n");
                       who->set_temp("marks/谜", 6);
                       break;
                   case 6:
                       write("拱猪入门。(打一字)\n");
                    // this riddle made by 老哈（美国　明尼苏达大学）
                       who->set_temp("marks/谜", 7);
                       break;
                   case 7:
                       write("拱猪王闷闷不乐。(打一字)\n");
                    // this riddle modified from one made by 绿田　（美国　密执安州）
                       who->set_temp("marks/谜", 8);
                       break;
                   case 8:
                       write("锦帆才渡儿郎去。(打一本泥潭巫师网名)\n");
                    // this riddle made by 岳涵　（美国　密执安州）
                       who->set_temp("marks/谜", 9);
                       break;
                   case 9:
                       write("德意日战败。(打一本泥潭NPC名)\n");
                    // this riddle modified from one made by 牛　（美国）
                       who->set_temp("marks/谜", 10);
                       break;
                   case 10:
                       write("整年当兵。(打一本泥潭NPC名)\n");
                    // this riddle made by 四月　（美国）
                       who->set_temp("marks/谜", 11);
                       break;
                   case 11:
                       write("欧阳锋练功。(打一成语)\n");
                    // this riddle made by 魔　（美国）
                       who->set_temp("marks/谜", 12);
                       break;
                   case 12:
                       write("胡踢乱踹。(打一本泥潭NPC名)\n");
                    // this riddle made by 居士　（美国）
                       who->set_temp("marks/谜", 13);
                       break;
                   case 13:
                       write("麦克杰克逊。(打二本泥潭NPC名)----回答时二名一起回答，中间不加任何标点。\n");
                       who->set_temp("marks/谜", 14);
                       break;
                   case 14:
                       write("召。(打二本泥潭NPC名)----回答时二名一起回答，中间不加任何标点。\n");
                    // this riddle made by 老哈　（美国）
                       who->set_temp("marks/谜", 15);
                       break;
                   case 15:
                       write("圣旨。(打一本泥潭玩家名)\n");
                       who->set_temp("marks/谜", 16);
                       break;
                   case 16:
                       write("缘何一夕梦未成。(打一本泥潭门派名)\n");
                    // this riddle made by 老哈　（美国） hanxx002@maroon.tc.umn.edu
                       who->set_temp("marks/谜", 17);
                       break;
                   case 17:
                       write("唐乐。(打一本泥潭NPC名)\n");
                    // this riddle made by ★魔　（美国） ning@phish.ecii.org
                       who->set_temp("marks/谜", 18);
                       break;
                   case 18:
                       write("一样的不止一点两点。(打一本泥潭地名及一技能名)\n");
                       who->set_temp("marks/谜", 19);
		       break;
                   case 19:
                       write("回扣。(打一本泥潭NPC名)\n");
                       who->set_temp("marks/谜", 20);
                       break;

                  }
                  write("想好了回答 (answer) 我。记住，不可泄露谜语或谜底。\n");
                  message("vision", "阿凡提对着"+who->name()+"嘀咕了几句话。\n",
                          environment(who), ({who}) );
                  remove_call_out("destroying");
                  call_out("destroying", 1, this_object(), ob);
                  return 1;
            }
      }
}

void destroying(object me, object obj)
{
        destruct(obj);
        return;
}
int do_answer(string arg)
{
        object me,gold;
        int soln,riddle;
        me = this_player();
        riddle = this_player()->query_temp("marks/谜");

        if (!riddle) {
           write("我又不是你师傅，你用不着回答我。\n");
           return 1;
        }

        if( !arg || arg=="" ) {
           write("想好谜底再回答。\n");
           return 1;
        }
        message("vision", me->name() + "把嘴凑到阿凡提的耳边嘀嘀咕咕。\n",
                 environment(me), ({me}) );

        switch (arg) {
          case "姗": soln=1; break;
          case "灵灵" : soln=2; break;
          case "江百胜" : soln=3; break;
          case "玫" : soln=4; break;
          case "二娃" : soln=5; break;
          case "道学心法" : soln=6; break;
          case "阂" : soln=7; break;
          case "氦" : soln=8; break;
          case "方舟子" : soln=9; break;
          case "欧阳克" : soln=10; break;
          case "丁春秋" : soln=11; break;
          case "倒行逆施" : soln=12; break;
          case "鲁有脚" : soln=13; break;
          case "黑无常白无常":
          case "白无常黑无常": soln=14; break;
          case "欧阳锋欧阳克": soln=15; break;
          case "龙云": soln=16; break;
	  case "少林": soln=17; break;
	  case "李莫愁" : soln=18; break;
	  case "逍遥洞逍遥游" : soln=19; break;
          case "买卖提" : soln=20; break;
          default :
              say("阿凡提大笑起来，说道：你说什么呀，牛头不对马嘴。\n"
                  + me->name() + "的脸被臊得通红。\n");
              return 1;
        }
        if (me->query("combat_exp")>10)
        {
              say("阿凡提大笑起来，说道：你还来骗经验呀。\n" + me->name() + "的脸被臊得通红。\n");
              return 1;
        }
        if (riddle==soln) {
//          gold = new("clone/money/gold");
//          gold->move(this_player());
//          say("阿凡提给了" + me->name() + "一两黄金。\n");
          this_player()->set_temp("marks/谜", 0);
          say ("阿凡提对" + me->name() + "竖起大姆指：居然让你猜着了。黄金是巴依的不义之财，你拿去分给穷人吧。\n");
          this_player()->set("combat_exp",this_player()->query("combat_exp")+80);
          write ("你的经验增加了！\n");

        }
        else
          write ("谁把谜底告诉你的? 不对!!\n");
        return 1;
} 
 

   
