// 这是玩家自创武功程序。
// waiter
// 店小二
// 武林至尊逍遥派护法使者
// 15395700
// 男性
// unarmed
// 玄冥神掌
#include <ansi.h>
inherit SKILL;
string type() { return "martial"; }
string martialtype() { return "skill"; }
string owner() {return "waiter";}

mapping *action = ({
// ZHAOSHI :0
([
	"action" : "$N左手虚晃两招，忽的一个窜步攻到$n身前，右掌一式「冷刃诀」，直拍$n某的部位。[2;37;0m",
	"lvl" : 0,
	"skill_name" : "冷刃诀",
]),
// ZHAOSHI :1
([
	"action" : "$N左脚虚踏，全身右转，一招「断肠诀」，右掌猛地插向$n的$l。[2;37;0m",
	"lvl" : 20,
	"skill_name" : "断肠诀",
]),
// ZHAOSHI :2
([
	"action" : "$N左掌圈花扬起，屈肘当胸，虎口朝上，一招「催心诀」打向$n的$l。[2;37;0m",
	"lvl" : 40,
	"skill_name" : "催心诀",
]),
// ZHAOSHI :3
([
	"action" : "$N使一招「震魂诀」，上身前探，双手划了个半圈，击向$n的$l。[2;37;0m",
	"lvl" : 60,
	"skill_name" : "震魂诀",
]),
});
// ZHAOSHI :4
int valid_learn(object me)
{
	string creater;

	if( (int)me->query("max_neili") < 50 )
		return notify_fail("你的内力太弱，无法练"+"玄冥神掌"+"。\n");
	if( me->query_temp("weapon") || me->query_temp("secondary_weapon") )
		return notify_fail("练"+"玄冥神掌"+"必须空手。\n");
	creater = this_object()->owner();
	if (userp(me) &&
	me->query("id")!=creater && 
	me->query("couple/couple_id")!=creater)
	return notify_fail("不能向其他玩家学习自创的武功。\n");
	return 1;
}
int valid_enable(string usage)
{
	return usage== "unarmed" || usage=="parry";
}
int practice_skill(object me)
{
	string skname=explode(__FILE__,"/")[<1][0..<3];
	int lvl = me->query_skill(skname,1);
	int i=sizeof(action);
	int qicost;
	int nlcost;

	qicost = (126 + 231)/10;
	nlcost = (126 + 231)/15;
	if( (int)me->query("qi") < qicost )
		return notify_fail("你的体力不够了，休息一下再练吧。\n");
	if( (int)me->query("neili") < nlcost )
		return notify_fail("你的内力不够了，休息一下再练吧。\n");
	me->receive_damage("qi", qicost);
	me->add("neili", -nlcost);
	if (lvl>=action[i-1]["lvl"]+20)
		return notify_fail("这一招你已经练到顶了，该钻研钻研新的招式了。\n");
	return 1;
}
string query_skill_name(int level)
{
	int i;
	for(i = sizeof(action); i > 0; i--)
		if(level >= action[i-1]["lvl"])
			return action[i-1]["skill_name"];
}
mapping query_action(object me, object weapon)
{
/* d_e=dodge_effect p_e=parry_effect f_e=force_effect m_e=damage_effect */
	int d_e1 = 18;
	int d_e2 = 0;
	int p_e1 = 39;
	int p_e2 = 23;
	int f_e1 = 126;
	int f_e2 = 231;
	int i, lvl, seq, ttl = sizeof(action);

	lvl = (int) me->query_skill("xuanminzhang-unarmed", 1);
	for(i = ttl; i > 0; i--)
		if(lvl > action[i-1]["lvl"])
		{
			seq = i; /* 获得招数序号上限 */
			break;
		}
	seq = random(seq);       /* 选择出手招数序号 */
	return ([
		"action"      : action[seq]["action"],
		"dodge"       : d_e1 + (d_e2 - d_e1) * seq / ttl,
		"parry"       : p_e1 + (p_e2 - p_e1) * seq / ttl,
		"force"       : f_e1 + (f_e2 - f_e1) * seq / ttl,
                "damage_type" : random(2) ? "内伤" : "瘀伤",
	]);
}
int learn_bonus() { return 20; }
int practice_bonus() { return 20; }
int success() { return 10; }
int power_point(object me) { return 1.0; }

string perform_action_file(string action)
{
	return __DIR__+"xuanminzhang-unarmed"+"/" + action;
}
int help(object me)
{
	write(HIC"\n"+"玄冥神掌"+"："NOR"\n");
	write(@HELP

	玄冥神掌为西域绝学之一，至阴至寒，威力极大。
HELP
	);
	return 1;
}