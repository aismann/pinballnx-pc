#ifndef GTARGET_H_
#define GTARGET_H_

#include <list>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include "Box2D/Box2D.h"
#include "util.h"
#include "SceneElement.h"

using namespace sf;
using namespace std;

class GTarget {
    public:
        GTarget(SceneElement* root, b2World& world, int targetGroupID, int layerID, bool sameSprites = false, bool collide = false, bool dontReset = false);
        vector<b2Fixture*> getFixtures();
        void update();
        bool press(size_t targetID); // Returns true if all targets are pressed
        bool isPressed(size_t targetID);
        void reset();
    private:
        int m_layerID;
        bool m_collide;
        bool m_dontReset;
        vector<b2Fixture*> m_fixtures;
        vector<bool> m_isPressed;
        vector<int> m_dropTimers;
        int m_dropTime = 10;
		SoundBuffer* m_sound;
		vector<Sound*> m_sounds;
        vector<SceneElement*> m_eltsEnabled;
        vector<SceneElement*> m_eltsDisabled;
        int m_hitFrames = 32 * g_displayFrameRate / 60;
        int m_frameCurrent = m_hitFrames + 1;
        vector<float> m_rightTarget0 = {528.6, 567.3, 516.7, 572.5, 515.7, 574.2, 514.6, 575.8, 515.9, 577.4, 517.2, 579.0, 518.5, 579.0, 519.8, 579.0, 531.6, 574.0, 543.4, 569.0, 544.9, 567.5, 546.5, 566.0, 545.4, 564.2, 544.3, 562.5, 542.4, 562.3, 540.5, 562.1, 528.6, 567.3};
        vector<float> m_rightTarget1 = {563.6, 553.5, 552.6, 557.9, 551.2, 559.4, 549.7, 560.8, 550.3, 562.4, 551.0, 564.0, 552.4, 564.6, 553.9, 565.2, 565.9, 560.5, 577.8, 555.9, 579.1, 554.4, 580.4, 552.8, 579.3, 551.2, 578.3, 549.5, 576.4, 549.3, 574.5, 549.2, 563.6, 553.5};
        vector<float> m_rightTarget2 = {595.3, 540.9, 586.0, 544.7, 584.5, 546.0, 583.0, 547.2, 583.0, 548.5, 583.0, 549.8, 584.5, 551.0, 586.0, 552.2, 596.1, 548.5, 606.2, 544.7, 608.3, 542.9, 610.5, 541.1, 609.4, 539.3, 608.3, 537.5, 606.4, 537.3, 604.5, 537.1, 595.3, 540.9};
        vector<float> m_rightReturn0 = {207.9, 640.6, 206.6, 642.2, 207.7, 643.8, 208.7, 645.5, 227.0, 645.5, 245.3, 645.5, 246.3, 643.8, 247.4, 642.2, 246.1, 640.6, 244.8, 639.0, 227.0, 639.0, 209.2, 639.0, 207.9, 640.6};
        vector<float> m_rightReturn1 = {207.9, 605.6, 206.6, 607.2, 207.7, 608.8, 208.7, 610.5, 227.0, 610.5, 245.3, 610.5, 246.3, 608.8, 247.4, 607.2, 246.1, 605.6, 244.8, 604.0, 227.0, 604.0, 209.2, 604.0, 207.9, 605.6};
        vector<float> m_rightReturn2 = {207.9, 571.6, 206.6, 573.2, 207.7, 574.8, 208.7, 576.5, 227.0, 576.5, 245.3, 576.5, 246.3, 574.8, 247.4, 573.2, 246.1, 571.6, 244.8, 570.0, 227.0, 570.0, 209.2, 570.0, 207.9, 571.6};
        vector<float> m_leftReturn0 = {207.9, 97.6, 206.6, 99.2, 207.7, 100.8, 208.7, 102.5, 227.0, 102.5, 245.3, 102.5, 246.3, 100.8, 247.4, 99.2, 246.1, 97.6, 244.8, 96.0, 227.0, 96.0, 209.2, 96.0, 207.9, 97.6};
        vector<float> m_leftReturn1 = {207.9, 62.6, 206.6, 64.2, 207.7, 65.8, 208.7, 67.5, 227.0, 67.5, 245.3, 67.5, 246.3, 65.8, 247.4, 64.2, 246.1, 62.6, 244.8, 61.0, 227.0, 61.0, 209.2, 61.0, 207.9, 62.6};
        vector<float> m_leftReturn2 = {207.9, 28.6, 206.6, 30.2, 207.7, 31.8, 208.7, 33.5, 227.0, 33.5, 245.3, 33.5, 246.3, 31.8, 247.4, 30.2, 246.1, 28.6, 244.8, 27.0, 227.0, 27.0, 209.2, 27.0, 207.9, 28.6};
        vector<float> m_middleTarget0 = {732.4, 296.5, 731.8, 298.0, 734.0, 307.3, 736.3, 316.5, 737.2, 318.2, 738.1, 320.0, 739.5, 320.0, 740.9, 320.0, 741.5, 319.1, 742.0, 318.1, 740.1, 310.8, 738.1, 303.5, 737.0, 299.2, 735.9, 295.0, 734.4, 295.0, 732.9, 295.0, 732.4, 296.5};
        vector<float> m_middleTarget1 = {724.4, 268.4, 723.9, 269.7, 726.0, 278.1, 728.1, 286.5, 729.1, 289.7, 730.2, 293.0, 731.6, 293.0, 733.1, 293.0, 733.6, 291.5, 734.2, 289.9, 732.0, 280.2, 729.8, 270.5, 728.8, 268.7, 727.9, 267.0, 726.4, 267.0, 724.9, 267.0, 724.4, 268.4};
        vector<float> m_middleTarget2 = {716.4, 240.4, 715.8, 242.0, 718.5, 253.1, 721.3, 264.2, 722.7, 264.7, 724.1, 265.3, 725.3, 264.1, 726.4, 263.0, 723.5, 251.2, 720.5, 239.5, 718.7, 239.2, 717.0, 238.9, 716.4, 240.4};
        vector<float> m_launchTarget0 = {517.7, 677.6, 517.0, 678.3, 517.0, 680.7, 517.0, 683.0, 515.0, 685.0, 513.0, 687.0, 513.0, 689.5, 513.0, 692.0, 514.9, 693.9, 516.8, 695.8, 517.2, 698.2, 517.5, 700.5, 519.5, 700.5, 521.5, 700.5, 521.8, 698.2, 522.2, 695.8, 524.1, 693.9, 526.0, 692.0, 526.0, 689.5, 526.0, 687.0, 524.1, 685.1, 522.1, 683.1, 521.8, 680.3, 521.5, 677.5, 520.0, 677.2, 518.4, 676.9, 517.7, 677.6};
        vector<float> m_launchTarget1 = {598.7, 677.6, 598.0, 678.3, 598.0, 680.7, 598.0, 683.0, 596.0, 685.0, 594.0, 687.0, 594.0, 689.5, 594.0, 692.0, 595.9, 693.9, 597.8, 695.8, 598.2, 698.2, 598.5, 700.5, 600.5, 700.5, 602.5, 700.5, 602.8, 698.2, 603.2, 695.8, 605.1, 693.9, 607.0, 692.0, 607.0, 689.5, 607.0, 687.0, 605.1, 685.1, 603.1, 683.1, 602.8, 680.3, 602.5, 677.5, 601.0, 677.2, 599.4, 676.9, 598.7, 677.6};
        vector<float> m_launchTarget2 = {679.7, 677.6, 679.0, 678.3, 679.0, 680.7, 679.0, 683.0, 677.0, 685.0, 675.0, 687.0, 675.0, 689.5, 675.0, 692.0, 676.9, 693.9, 678.8, 695.8, 679.2, 698.2, 679.5, 700.5, 681.5, 700.5, 683.5, 700.5, 683.8, 698.2, 684.2, 695.8, 686.1, 693.9, 688.0, 692.0, 688.0, 689.5, 688.0, 687.0, 686.1, 685.1, 684.1, 683.1, 683.8, 680.3, 683.5, 677.5, 682.0, 677.2, 680.4, 676.9, 679.7, 677.6};
        vector<float> m_launchTarget3 = {760.7, 677.6, 760.0, 678.3, 760.0, 680.7, 760.0, 683.0, 758.0, 685.0, 756.0, 687.0, 756.0, 689.5, 756.0, 692.0, 757.9, 693.9, 759.8, 695.8, 760.2, 698.2, 760.5, 700.5, 762.5, 700.5, 764.5, 700.5, 764.8, 698.2, 765.2, 695.8, 767.1, 693.9, 769.0, 692.0, 769.0, 689.5, 769.0, 687.0, 767.1, 685.1, 765.1, 683.1, 764.8, 680.3, 764.5, 677.5, 763.0, 677.2, 761.4, 676.9, 760.7, 677.6};
        vector<float> m_launchTarget4 = {841.7, 677.6, 841.0, 678.3, 841.0, 680.7, 841.0, 683.0, 839.0, 685.0, 837.0, 687.0, 837.0, 689.5, 837.0, 692.0, 838.9, 693.9, 840.8, 695.8, 841.2, 698.2, 841.5, 700.5, 843.5, 700.5, 845.5, 700.5, 845.8, 698.2, 846.2, 695.8, 848.1, 693.9, 850.0, 692.0, 850.0, 689.5, 850.0, 687.0, 848.1, 685.1, 846.1, 683.1, 845.8, 680.3, 845.5, 677.5, 844.0, 677.2, 842.4, 676.9, 841.7, 677.6};
        vector<float> m_launchTarget5 = {922.7, 677.6, 922.0, 678.3, 922.0, 680.7, 922.0, 683.0, 920.0, 685.0, 918.0, 687.0, 918.0, 689.5, 918.0, 692.0, 919.9, 693.9, 921.8, 695.8, 922.2, 698.2, 922.5, 700.5, 924.5, 700.5, 926.5, 700.5, 926.8, 698.2, 927.2, 695.8, 929.1, 693.9, 931.0, 692.0, 931.0, 689.5, 931.0, 687.0, 929.1, 685.1, 927.1, 683.1, 926.8, 680.3, 926.5, 677.5, 925.0, 677.2, 923.4, 676.9, 922.7, 677.6};
        vector<float> m_m = {778.7, 210.6, 778.0, 211.3, 778.0, 215.0, 778.0, 218.6, 776.8, 219.8, 775.6, 221.0, 776.8, 223.2, 777.9, 225.5, 778.2, 228.0, 778.5, 230.5, 780.5, 230.5, 782.5, 230.5, 782.8, 227.5, 783.2, 224.5, 784.2, 223.2, 785.3, 221.9, 784.2, 219.7, 783.1, 217.5, 782.8, 214.0, 782.5, 210.5, 781.0, 210.2, 779.4, 209.9, 778.7, 210.6};
        vector<float> m_u = {778.7, 243.6, 778.0, 244.3, 778.0, 248.0, 778.0, 251.6, 776.8, 252.8, 775.6, 254.0, 776.8, 256.2, 777.9, 258.5, 778.2, 261.0, 778.5, 263.5, 780.5, 263.5, 782.5, 263.5, 782.8, 260.5, 783.2, 257.5, 784.2, 256.2, 785.3, 254.9, 784.2, 252.7, 783.1, 250.5, 782.8, 247.0, 782.5, 243.5, 781.0, 243.2, 779.4, 242.9, 778.7, 243.6};
        vector<float> m_l = {778.7, 278.6, 778.0, 279.3, 778.0, 283.0, 778.0, 286.6, 776.8, 287.8, 775.6, 289.0, 776.8, 291.2, 777.9, 293.5, 778.2, 296.0, 778.5, 298.5, 780.5, 298.5, 782.5, 298.5, 782.8, 295.5, 783.2, 292.5, 784.2, 291.2, 785.3, 289.9, 784.2, 287.7, 783.1, 285.5, 782.8, 282.0, 782.5, 278.5, 781.0, 278.2, 779.4, 277.9, 778.7, 278.6};
        vector<float> m_t = {618.4, 546.5, 617.8, 548.1, 623.0, 562.1, 628.3, 576.2, 629.7, 576.7, 631.1, 577.3, 632.3, 576.1, 633.5, 574.9, 631.2, 568.7, 629.0, 562.5, 629.0, 560.4, 629.0, 558.4, 627.8, 557.2, 626.6, 556.0, 624.5, 550.7, 622.4, 545.5, 620.7, 545.2, 619.0, 544.9, 618.4, 546.5};
        vector<float> m_i = {449.5, 614.9, 448.5, 615.9, 445.0, 616.2, 441.5, 616.5, 441.5, 618.5, 441.5, 620.5, 457.0, 620.5, 472.5, 620.5, 472.5, 618.5, 472.5, 616.5, 467.0, 616.2, 461.5, 615.9, 460.6, 614.9, 459.6, 614.0, 455.0, 614.0, 450.4, 614.0, 449.5, 614.9};

        vector<vector<float>> m_rightGroup = {
            m_rightTarget0, m_rightTarget1, m_rightTarget2
        };
        vector<vector<float>> m_rightReturn = {
            m_rightReturn0, m_rightReturn1, m_rightReturn2
        };
        vector<vector<float>> m_leftReturn = {
            m_leftReturn0, m_leftReturn1, m_leftReturn2
        };
        vector<vector<float>> m_middleTargets = {
            m_middleTarget0, m_middleTarget1, m_middleTarget2
        };
        vector<vector<float>> m_launchTargets = {
            m_launchTarget0, m_launchTarget1, m_launchTarget2, m_launchTarget3, m_launchTarget4, m_launchTarget5
        };
        vector<vector<float>> m_multiTargets = {
            m_m, m_u, m_l, m_t, m_i
        };
        vector<vector<vector<float>>> m_targetGroups = {
            m_rightGroup, m_rightReturn, m_leftReturn, m_middleTargets, m_launchTargets, m_multiTargets
        };
        vector<vector<float>> m_positions = {
            {
                515, 553,
                550, 540,
                583, 529
            },
            {
                207, 636,
                207, 602,
                207, 568
            },
            {
                207, 94,
                207, 60,
                207, 26
            },
            {
                722, 295,
                714, 267,
                706, 239
            },
            {
                517, 677,
                598, 677,
                679, 677,
                760, 677,
                841, 677,
                922, 677
            },
            {
                743, 213,
                747, 245,
                751, 276,
                618, 543,
                436, 588
            }
        };
};

#endif