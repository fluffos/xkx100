//Cracked by Kafei
// /d/shenlong/sgjob/sgjob20000.c

// inherit SKILL;

inherit F_CLEAN_UP;

mapping *sgjobs = ({
        ([      "sgjob":          "道德经",
                "sgjob_type":           "寻",
                "exp_bonus":             10,
                "pot_bonus":             3,
                "score":                 1
        ]),

        ([      "sgjob":          "『星宿毒经』",
                "sgjob_type":           "寻",
                "exp_bonus":             30,
                "pot_bonus":             8,
                "score":                 1
        ]),

        ([      "sgjob":          "持世陀罗尼经",
                "sgjob_type":           "寻",
                "exp_bonus":             40,
                "pot_bonus":             10,
                "score":                 1
        ]),

        ([      "sgjob":          "铁八卦",
                "sgjob_type":           "寻",
                "exp_bonus":             120,
                "pot_bonus":             30,
                "score":                 2
        ]),

        ([      "sgjob":          "华山剑谱",
                "sgjob_type":           "寻",
                "exp_bonus":             150,
                "pot_bonus":             40,
                "score":                 2
        ]),

        ([      "sgjob":          "唐诗选辑",
                "sgjob_type":           "寻",
                "exp_bonus":             150,
                "pot_bonus":             40,
                "score":                 2
        ]),

        ([      "sgjob":          "胡家刀法残篇",
                "sgjob_type":           "寻",
                "exp_bonus":             250,
                "pot_bonus":             60,
                "score":                 2
        ]),

        ([      "sgjob":          "少林英雄令",
                "sgjob_type":           "寻",
                "exp_bonus":             120,
                "pot_bonus":             30,
                "score":                 1
        ]),

        ([      "sgjob":          "罚恶令",
                "sgjob_type":           "寻",
                "exp_bonus":             100,
                "pot_bonus":             25,
                "score":                 2
        ]),

        ([      "sgjob":          "赏善令",
                "sgjob_type":           "寻",
                "exp_bonus":             100,
                "pot_bonus":             25,
                "score":                 2
        ]),

        ([      "sgjob":          "正气诀诀谱上卷",
                "sgjob_type":           "寻",
                "exp_bonus":             30,
                "pot_bonus":             8,
                "score":                 1
        ]),

        ([      "sgjob":          "正气诀诀谱下卷",
                "sgjob_type":           "寻",
                "exp_bonus":             30,
                "pot_bonus":             8,
                "score":                 1
        ]),

        ([      "sgjob":          "紫氤吟诀谱上卷",
                "sgjob_type":           "寻",
                "exp_bonus":             30,
                "pot_bonus":             8,
                "score":                 1
        ]),

        ([      "sgjob":          "紫氤吟诀谱下卷",
                "sgjob_type":           "寻",
                "exp_bonus":             30,
                "pot_bonus":             8,
                "score":                 1
        ]),

        ([      "sgjob":          "FORCEJOIN",
        ]),

        ([      "sgjob":          "FORCEJOIN",
        ]),

        ([      "sgjob":          "FORCEJOIN",
        ]),

        ([      "sgjob":          "FORCEJOIN",
        ]),

        ([      "sgjob":          "FORCEJOIN",
        ]),

        ([      "sgjob":          "FORCEJOIN",
        ]),

        ([      "sgjob":          "FORCEJOIN",
        ]),

        ([      "sgjob":          "FORCEJOIN",
        ]),

        ([      "sgjob":          "FORCEJOIN",
        ]),

        ([      "sgjob":          "FORCEJOIN",
        ]),

        ([      "sgjob":          "PK",
        ]),

        ([      "sgjob":          "PK",
        ]),

        ([      "sgjob":          "PK",
        ]),

        ([      "sgjob":          "PK",
        ]),

        ([      "sgjob":          "PK",
        ]),
});

void create() { seteuid(getuid()); }

mapping query_sgjob()
{
        return sgjobs[random(sizeof(sgjobs))];
}


