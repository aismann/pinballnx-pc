#ifndef PTARGET_H_
#define PTARGET_H_

#include <list>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include "Box2D/Box2D.h"
#include "util.h"
#include "SceneElement.h"

using namespace sf;
using namespace std;

class PTarget {
    public:
        PTarget(SceneElement* root, b2World& world, int targetGroupID, int layerID);
        vector<b2Fixture*> getFixtures();
        void update();
        bool isCurrent(size_t targetID);
        bool press(size_t targetID); // Returns true if the last target in the progression was pressed.
        void reset();
    private:
        int m_layerID;
        vector<b2Fixture*> m_fixtures;
        vector<SceneElement*> m_eltsEnabled;
        vector<SceneElement*> m_eltsDisabled;
        size_t m_currentTarget = 0;
        int m_flashTimer = 0;
        int m_flashFrames = 32 * g_displayFrameRate / 60;
        int m_frame = 0;
		SoundBuffer* m_sound1;
		SoundBuffer* m_sound2;
		vector<Sound*> m_sounds;
        vector<float> m_rightRamp = {792.0, 588.4, 784.5, 591.6, 770.3, 597.5, 756.0, 603.4, 755.5, 605.0, 755.0, 606.7, 755.5, 608.3, 756.1, 609.8, 766.6, 616.9, 777.1, 624.0, 778.3, 624.0, 779.5, 624.0, 800.3, 616.9, 821.2, 609.7, 822.6, 608.3, 824.0, 606.9, 824.0, 605.2, 824.0, 603.6, 819.3, 599.2, 814.5, 594.7, 808.7, 589.9, 802.9, 585.0, 801.2, 585.1, 799.5, 585.1, 792.0, 588.4};
        vector<float> m_leftRamp = {996.6, 66.5, 995.1, 68.1, 990.5, 82.4, 986.0, 96.8, 986.0, 97.8, 986.0, 98.9, 987.6, 100.4, 989.1, 102.0, 1004.7, 102.0, 1020.2, 102.0, 1023.7, 98.2, 1027.2, 94.5, 1029.8, 90.7, 1032.3, 87.0, 1031.4, 85.0, 1030.5, 83.0, 1015.6, 74.0, 1000.7, 65.0, 999.4, 65.0, 998.1, 65.0, 996.6, 66.5};
        vector<float> m_topRightRamp = {1029.9, 578.0, 1028.3, 578.9, 1024.5, 584.4, 1020.8, 589.8, 1021.4, 591.7, 1022.0, 593.5, 1029.2, 599.6, 1036.5, 605.6, 1039.2, 607.4, 1041.9, 609.2, 1043.8, 608.5, 1045.8, 607.9, 1050.4, 603.0, 1055.0, 598.1, 1055.0, 596.4, 1055.0, 594.8, 1051.9, 591.9, 1048.7, 588.9, 1041.3, 583.0, 1033.9, 577.0, 1032.7, 577.0, 1031.5, 577.1, 1029.9, 578.0};

        vector<float> m_middleHole = {789.0, 390.7, 787.5, 391.2, 784.8, 393.8, 782.0, 396.4, 782.0, 399.0, 782.0, 401.6, 783.6, 403.8, 785.1, 406.0, 788.0, 407.5, 790.9, 409.0, 794.3, 409.0, 797.6, 409.0, 800.3, 406.2, 803.0, 403.4, 803.0, 400.1, 803.0, 396.8, 799.6, 393.4, 796.2, 390.0, 793.4, 390.1, 790.5, 390.2, 789.0, 390.7};
        vector<float> m_leftHole = {1064.2, 17.2, 1063.0, 18.4, 1063.0, 21.6, 1063.0, 24.8, 1061.5, 26.0, 1060.0, 27.2, 1060.0, 28.5, 1060.0, 29.8, 1061.5, 31.0, 1063.0, 32.2, 1063.0, 35.5, 1063.0, 38.8, 1064.6, 40.1, 1066.2, 41.4, 1067.8, 40.3, 1069.5, 39.3, 1069.8, 35.9, 1070.1, 32.5, 1071.2, 30.2, 1072.4, 28.0, 1071.2, 26.8, 1070.0, 25.6, 1070.0, 22.0, 1070.0, 18.4, 1068.8, 17.2, 1067.6, 16.0, 1066.5, 16.0, 1065.4, 16.0, 1064.2, 17.2};
        vector<float> m_lowerHole = {771.4, 368.4, 768.0, 371.8, 768.0, 374.3, 768.0, 376.9, 770.6, 378.9, 773.3, 381.0, 776.3, 381.0, 779.4, 381.0, 782.2, 378.3, 785.0, 375.6, 785.0, 372.4, 785.0, 369.1, 782.4, 367.1, 779.7, 365.0, 777.3, 365.0, 774.8, 365.0, 771.4, 368.4};
        vector<float> m_upperHole = {811.2, 432.3, 809.0, 434.6, 809.0, 437.7, 809.0, 440.8, 813.1, 444.5, 817.2, 448.2, 819.8, 447.5, 822.5, 446.9, 824.8, 444.4, 827.0, 441.9, 827.0, 437.6, 827.0, 433.3, 825.2, 431.7, 823.3, 430.0, 818.3, 430.0, 813.3, 430.0, 811.2, 432.3};

        vector<vector<float>> m_rampGroup = {
            m_rightRamp, m_leftRamp, m_topRightRamp
        };

        vector<vector<float>> m_holeGroup = {
            m_middleHole, m_leftHole, m_lowerHole, m_upperHole
        };

        vector<vector<vector<float>>> m_targetGroups = {
            m_rampGroup, m_holeGroup
        };

        vector<vector<float>> m_positions = {
            {
                723, 545,
                768, 111,
                1020, 581
            },
            {
                852, 335,
                1104, 13,
                711, 333,
                873, 395
            }
        };
};

#endif