// jiefei.c 黄河帮劫匪
#include <ansi.h>
#include "jinit.h"
inherit NPC;
string *xing=({"赵","钱","孙","李","周","吴","郑","王","冯","陈","褚","卫","蒋","沈","韩","杨","朱","秦","尤","许","何","吕","施","张","孔","曹","严","华","金","魏","陶","姜","戚","谢","邹","喻","柏","水","窦","章","云","苏","潘","葛","奚","范","彭","郎","鲁","韦","昌","马","苗","凤","花","方","俞","任","袁","柳","酆","鲍","史","唐","费","廉","岑","薛","雷","贺","倪","汤","滕","殷","罗","毕","郝","邬","安","常","乐","于","时","傅","皮","卞","齐","康","伍","余","元","卜","顾","孟","平","黄","和","穆","萧","尹","姚","邵"}); 
	string *id=({"zhao","qian","sun","li","zhou","wu","zheng","wang","feng","chen","zhu","wei","jiang","shen","han","yang","zhu","qin","you","xu","he","lv","shi","zhang","kong","cao","yan","hua","jin","wei","tao","jiang","qi","xie","zou","yu","bai","shui","dou","zhang","yun","su","pan","ge","xi","fan","pen","lang","lu","wei","chang","ma","miao","feng","hua","fang","yu","ren","yuan","liu","feng","bao","shi","tang","fei","lian","cen","xue","lei","he","ni","tang","teng","yin","luo","bi","hao","wu","an","chang","le","yu","shi","fu","pi","bian","qi","kang","wu","yu","yuan","piao","gu","meng","ping","huang","he","mu","xiao","yin","yao","shao"}); 
	string *ming1=({"天","地","玄","黄","宇","宙","洪","荒","日","月","盈","昃","辰","宿","列","寒","来","暑","往","秋","冬","馀","成","律","阳","云","腾","雨","露","霜","金","生","丽","水","玉","昆","冈","剑","巨","阙","珠","夜","光","珍","重","海","河","鳞","羽","翔","龙","师","火","帝","鸟","官","人","皇","文","裳","国","陶","民","周","发","殷","汤","朝","道","垂","拱","平","章","爱","育","黎","首","臣","伏","宾","王","鸣","凤","竹","白","驹","化","草","木"}); 
	string *ming2=({"天","地","玄","黄","宇","宙","洪","荒","日","月","盈","昃","辰","宿","列","律","阳","云","腾","雨","露","霜","金","生","丽","水","玉","昆","冈","剑","巨","阙","珠","夜","光","珍","重","海","河","鳞","羽","翔","龙","官","人","皇","文","裳","国","陶","民","周","发","殷","汤","朝","道","垂","拱","平","章","爱","育","黎","首","臣","伏","宾","长","信","器","诗","景","行","贤","克","圣","德","建","名","立","形","端","表","正","空","谷","传","声"}); 

void create()
{
	int i;
	i = random(sizeof(xing));
	set_name(xing[i]+ming1[random(sizeof(ming1))]+ming2[random(sizeof(ming2))], ({id[i]}));
	set("title","黄河帮劫匪");
	set("long",
		"这是一位彪悍的北方汉子，一身黄河帮的黄衣。\n");
	set("gender", "男性" );
	set("age", 20 + random(25) );
	set("attitude", "heroism");
	set("str", 20 + random(11));	// 膂力
	set("per", 20 + random(11));	// 容貌
	set("int", 20 + random(11));	// 悟性
	set("con", 20 + random(11));	// 根骨
	set("dex", 20 + random(11)); 	// 身法
	set("kar", 20 + random(11));	// 福缘
	set("shen", -10);
	set("demogorgon",1);
	set("no_suck",1);
	set_temp("apply/attack", 40);
	set_temp("apply/defense", 40);
	set_temp("apply/damage", 40);
	set_temp("apply/armor", 40);
	set_temp("apply/dodge", 40);
	setup();
	set("chat_chance_combat", 20);
	set("chat_msg_combat", ({
		(: perform_action, "sword.ding" :),
		(: perform_action, "sword.sanqing" :),
		(: perform_action, "sword.chan" :),
		(: perform_action, "parry.ju" :),
		(: exert_function, "powerup" :),
		(: exert_function, "recover" :),
	}) );
	carry_object(__DIR__"obj/ycloth")->wear();
	carry_object("/clone/weapon/changjian")->wield();
	add_money("silver", 2);
}

