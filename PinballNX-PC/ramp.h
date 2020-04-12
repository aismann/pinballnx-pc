#ifndef RAMP_H_
#define RAMP_H_

#include<vector>
#include <SFML/Graphics.hpp>
#include "Box2D/Box2D.h"
#include "util.h"
#include "SceneElement.h"

using namespace std;

// The ramp class has a box2d body and fixture but they are only for detection purposes.
// The fixture in here is a box2d sensor and doesn't cause any forces. 
// The collision detection is handled in the Table class in the overriden
// BeginContact and EndContact methods from the b2ContactListener that Table extends.
// Creating a bidirectional ramp actually takes 2 Ramp objects, one for up and one for down
// because this class only transitions the pinball TO another layer. 
// This means you can also use this class to make holes that the ball can fall through but can't go up.
class Ramp {
    public:
        // C2DRenderer is only for debug graphics, can be removed if desired.
        // b2World is necessary for adding the sensor.
        // rampID specifies the collision shape to load.
        // layerID specifies the layer that the ramp transitions to.
        Ramp(SceneElement* root, b2World& world, int rampID, int fromLayer, int toLayer);
        b2Fixture* getFixture();
        int getLayerID();
    private:
        b2Fixture* m_fixture;
        int m_layerID;
        vector<float> m_ramp1 = {857.2, 70.3, 854.0, 73.6, 854.0, 75.1, 854.0, 76.7, 860.3, 86.4, 866.5, 96.1, 871.6, 103.3, 876.6, 110.5, 878.9, 110.8, 881.2, 111.2, 883.3, 109.3, 885.5, 107.3, 893.0, 102.8, 900.5, 98.3, 903.9, 97.1, 907.3, 96.0, 930.4, 96.0, 953.6, 96.0, 954.8, 94.8, 956.0, 93.6, 956.0, 91.5, 956.0, 89.4, 954.8, 88.2, 953.6, 87.0, 918.0, 87.0, 882.4, 87.0, 881.2, 85.8, 880.0, 84.6, 880.0, 82.5, 880.0, 80.4, 881.2, 79.2, 882.4, 78.0, 917.5, 78.0, 952.7, 78.0, 954.3, 76.2, 956.0, 74.3, 956.0, 72.2, 956.0, 70.1, 953.8, 68.6, 951.6, 67.0, 906.0, 67.0, 860.4, 67.0, 857.2, 70.3};
        vector<float> m_ramp1up2 = {983.4, 72.8, 979.3, 74.5, 977.6, 75.9, 975.9, 77.3, 974.0, 81.6, 972.0, 85.9, 972.0, 88.9, 972.0, 91.9, 973.2, 94.5, 974.3, 97.0, 979.3, 98.5, 984.4, 100.0, 1001.2, 100.0, 1018.1, 100.0, 1020.5, 97.5, 1023.0, 95.1, 1023.0, 91.0, 1023.0, 87.0, 1019.3, 82.9, 1015.7, 78.9, 1009.9, 76.1, 1004.2, 73.2, 999.1, 72.1, 993.9, 71.0, 990.7, 71.1, 987.5, 71.1, 983.4, 72.8};
        vector<float> m_ramp1Down = {807.0, 91.8, 775.5, 108.7, 775.2, 113.2, 774.9, 117.8, 780.1, 121.9, 785.3, 126.0, 787.0, 126.0, 788.8, 126.0, 793.6, 122.7, 798.5, 119.3, 801.2, 117.9, 803.9, 116.5, 811.7, 111.6, 819.5, 106.7, 823.0, 104.8, 826.4, 103.0, 829.8, 103.0, 833.1, 103.0, 835.5, 105.5, 838.0, 107.9, 838.0, 111.5, 838.0, 115.1, 835.6, 117.3, 833.2, 119.5, 826.6, 123.5, 819.9, 127.5, 814.2, 131.2, 808.5, 135.0, 803.2, 137.7, 799.5, 140.4, 799.4, 144.4, 800.1, 147.9, 804.4, 149.9, 808.8, 151.8, 811.7, 152.4, 814.7, 153.1, 839.6, 138.4, 864.5, 123.7, 865.8, 122.2, 867.0, 120.6, 867.0, 119.5, 867.0, 118.3, 855.4, 97.9, 843.7, 77.5, 842.2, 76.2, 840.6, 75.0, 839.6, 75.0, 838.5, 75.0, 807.0, 91.8};
        vector<float> m_ramp2 = {952.0, 632.6, 942.5, 634.9, 936.0, 635.0, 929.5, 635.0, 922.8, 635.7, 916.0, 636.3, 916.0, 639.6, 916.0, 643.0, 931.5, 643.0, 947.0, 643.0, 953.7, 640.5, 960.5, 637.9, 963.5, 638.2, 966.5, 638.5, 966.5, 641.5, 966.5, 644.4, 959.5, 647.1, 952.5, 649.9, 934.3, 649.9, 916.0, 650.0, 916.0, 653.9, 916.0, 657.7, 925.2, 658.4, 934.3, 659.0, 942.5, 659.0, 950.6, 659.0, 955.6, 657.6, 960.5, 656.2, 964.4, 655.5, 968.3, 654.9, 973.6, 652.5, 979.0, 650.1, 979.0, 648.9, 979.0, 647.8, 974.3, 638.9, 969.5, 630.0, 965.5, 630.1, 961.5, 630.2, 952.0, 632.6};
        vector<float> m_ramp2up2 = {998.0, 609.1, 992.5, 613.1, 987.5, 616.4, 982.5, 619.7, 980.6, 621.8, 978.8, 623.9, 979.4, 626.4, 980.0, 628.8, 984.1, 636.1, 988.2, 643.5, 989.6, 645.7, 991.0, 647.9, 998.5, 644.4, 1006.1, 641.0, 1007.4, 641.0, 1008.7, 641.0, 1015.1, 636.9, 1021.5, 632.8, 1024.8, 629.7, 1028.0, 626.6, 1028.0, 625.0, 1028.0, 623.3, 1026.2, 621.7, 1024.3, 620.0, 1022.9, 620.0, 1021.5, 620.0, 1014.8, 624.5, 1008.1, 629.0, 1002.6, 631.6, 997.1, 634.2, 995.3, 633.8, 993.5, 633.5, 993.2, 629.8, 992.9, 626.1, 999.2, 621.5, 1005.5, 617.0, 1009.3, 613.9, 1013.0, 610.9, 1013.0, 609.1, 1013.0, 607.4, 1011.8, 606.2, 1010.6, 605.0, 1007.1, 605.1, 1003.5, 605.1, 998.0, 609.};
        vector<float> m_ramp2Down = {1032.9, 582.9, 1026.2, 589.8, 1024.1, 591.0, 1021.9, 592.1, 1019.0, 596.2, 1016.0, 600.3, 1016.0, 601.6, 1016.0, 602.9, 1023.7, 611.5, 1031.4, 620.0, 1033.1, 620.0, 1034.8, 620.0, 1038.0, 617.4, 1041.1, 614.7, 1047.5, 606.6, 1053.8, 598.5, 1056.9, 595.6, 1060.0, 592.6, 1060.0, 590.8, 1060.0, 589.1, 1058.1, 588.0, 1056.1, 587.0, 1054.1, 587.0, 1052.1, 587.0, 1047.7, 591.7, 1043.2, 596.5, 1038.9, 601.7, 1034.5, 607.0, 1031.7, 607.0, 1028.9, 607.0, 1028.4, 605.5, 1027.8, 604.0, 1028.4, 601.7, 1029.0, 599.5, 1037.5, 590.1, 1046.0, 580.8, 1046.0, 579.4, 1046.0, 578.1, 1044.1, 577.0, 1042.1, 576.0, 1040.8, 576.0, 1039.5, 576.0, 1032.9, 582.9};
        vector<float> m_hole1 = {202.0, 64.0, 202.0, 83.0, 229.0, 83.0, 256.0, 83.0, 256.0, 64.0, 256.0, 45.0, 229.0, 45.0, 202.0, 45.0, 202.0, 64.0};
        vector<float> m_hole2 = {199.5, 600.2, 198.8, 609.5, 199.2, 615.0, 199.5, 620.5, 229.3, 620.8, 259.0, 621.0, 259.0, 606.0, 259.0, 591.0, 229.6, 591.0, 200.2, 591.0, 199.5, 600.2};
        vector<float> m_ramp3 = {743.2, 535.2, 742.0, 536.4, 742.0, 537.7, 742.0, 539.0, 743.2, 541.3, 744.5, 543.5, 747.6, 547.0, 750.8, 550.5, 751.4, 553.5, 752.1, 556.5, 752.7, 559.8, 753.2, 563.0, 752.0, 564.5, 750.8, 566.0, 747.5, 566.0, 744.3, 566.0, 742.5, 564.0, 740.7, 562.0, 739.5, 562.0, 738.3, 562.0, 735.3, 558.2, 732.3, 554.5, 731.1, 552.2, 729.9, 550.0, 728.5, 550.0, 727.1, 550.0, 723.1, 553.8, 719.2, 557.5, 718.5, 560.3, 717.8, 563.0, 718.5, 565.7, 719.2, 568.5, 725.9, 575.2, 732.7, 582.0, 738.3, 582.0, 743.9, 582.0, 749.7, 577.3, 755.5, 572.7, 763.3, 566.2, 771.1, 559.7, 770.8, 557.4, 770.5, 555.1, 761.0, 544.5, 751.5, 534.0, 748.0, 534.0, 744.4, 534.0, 743.2, 535.2};
        vector<float> m_ramp3Down = {703.2, 502.3, 698.5, 506.6, 691.1, 512.4, 683.8, 518.2, 680.9, 522.8, 678.0, 527.4, 678.0, 530.0, 678.0, 532.6, 686.8, 540.6, 695.6, 548.5, 697.9, 550.0, 700.3, 551.6, 699.6, 554.6, 698.9, 557.6, 696.9, 558.8, 694.9, 560.1, 691.0, 559.0, 687.1, 558.0, 683.0, 554.5, 678.9, 551.1, 675.6, 546.3, 672.3, 541.5, 669.1, 541.2, 665.9, 540.9, 664.3, 542.2, 662.7, 543.5, 663.3, 550.1, 663.9, 556.7, 666.1, 561.5, 668.3, 566.2, 671.4, 569.5, 674.5, 572.7, 680.2, 574.4, 685.8, 576.0, 695.7, 576.0, 705.7, 576.0, 707.8, 573.7, 710.0, 571.4, 711.9, 565.9, 713.8, 560.3, 715.4, 557.2, 717.0, 554.1, 720.1, 551.2, 723.3, 548.2, 722.6, 545.6, 722.0, 543.0, 713.0, 533.6, 704.0, 524.2, 704.0, 520.8, 704.0, 517.3, 706.3, 515.2, 708.6, 513.0, 711.1, 513.0, 713.6, 513.0, 718.2, 517.7, 722.8, 522.5, 724.7, 526.1, 726.6, 529.8, 729.3, 532.9, 732.0, 536.1, 734.7, 535.8, 737.5, 535.5, 738.4, 532.9, 739.3, 530.3, 736.7, 524.6, 734.1, 518.9, 726.3, 510.4, 718.5, 501.8, 714.8, 499.9, 711.1, 498.0, 709.5, 498.0, 707.9, 498.0, 703.2, 502.3};
        vector<float> m_ramp3up2 = {766.5, 574.4, 753.5, 583.7, 750.8, 586.3, 748.0, 588.9, 748.0, 593.7, 748.0, 598.6, 753.6, 605.3, 759.1, 612.1, 762.3, 613.4, 765.5, 614.8, 770.5, 615.9, 775.5, 616.9, 780.2, 617.6, 785.0, 618.2, 785.6, 616.6, 786.2, 615.0, 785.6, 612.6, 785.0, 610.2, 779.5, 602.1, 774.0, 594.0, 774.0, 591.7, 774.0, 589.4, 775.2, 588.2, 776.4, 587.0, 779.2, 587.0, 781.9, 587.0, 785.3, 590.0, 788.7, 592.9, 791.6, 597.2, 794.5, 601.5, 800.3, 607.5, 806.1, 613.4, 810.7, 611.0, 815.2, 608.6, 816.8, 606.2, 818.4, 603.8, 816.4, 600.2, 814.5, 596.5, 810.5, 592.5, 806.5, 588.5, 803.1, 584.0, 799.7, 579.5, 795.1, 574.6, 790.5, 569.8, 786.8, 567.4, 783.0, 565.0, 781.2, 565.0, 779.4, 565.0, 766.5, 574.4};
        vector<float> m_backdoorDown = {1108.0, 474.2, 1108.0, 543.5, 1106.6, 551.0, 1105.3, 558.5, 1103.5, 564.5, 1101.7, 570.5, 1099.8, 575.0, 1097.9, 579.4, 1092.2, 589.0, 1086.6, 598.5, 1082.9, 603.5, 1079.3, 608.5, 1064.3, 625.8, 1049.4, 643.1, 1040.0, 650.2, 1030.6, 657.3, 1019.6, 662.3, 1008.5, 667.2, 1001.0, 670.2, 993.5, 673.2, 987.1, 674.6, 980.7, 676.1, 978.8, 677.1, 976.9, 678.1, 968.7, 679.6, 960.5, 681.0, 719.2, 681.0, 477.8, 681.0, 475.1, 679.1, 472.4, 677.1, 469.7, 676.5, 467.1, 675.8, 465.9, 674.4, 464.8, 673.0, 458.1, 673.0, 451.4, 673.0, 450.2, 674.2, 449.0, 675.4, 449.0, 677.1, 449.0, 678.8, 454.3, 683.2, 459.5, 687.7, 467.0, 692.6, 474.5, 697.5, 712.0, 697.4, 949.5, 697.2, 964.0, 696.2, 978.5, 695.2, 983.0, 693.7, 987.5, 692.3, 991.5, 691.2, 995.5, 690.1, 1002.5, 688.4, 1009.5, 686.7, 1025.5, 678.6, 1041.5, 670.6, 1045.9, 667.8, 1050.3, 665.1, 1058.9, 656.8, 1067.5, 648.5, 1071.5, 645.5, 1075.5, 642.6, 1080.5, 637.4, 1085.5, 632.2, 1090.5, 626.0, 1095.5, 619.8, 1102.3, 610.6, 1109.0, 601.5, 1112.9, 593.5, 1116.9, 585.5, 1119.4, 579.5, 1121.9, 573.5, 1124.3, 565.9, 1126.8, 558.3, 1127.9, 550.4, 1129.1, 542.5, 1130.6, 532.5, 1132.0, 522.5, 1132.0, 463.7, 1132.0, 405.0, 1120.0, 405.0, 1108.0, 405.0, 1108.0, 474.2};
        vector<float> m_tunnelDown = {677.5, 12.3, 676.9, 13.6, 677.2, 29.0, 677.5, 44.5, 683.0, 44.8, 688.5, 45.1, 701.5, 39.1, 714.5, 33.1, 714.5, 22.3, 714.5, 11.5, 696.2, 11.2, 678.0, 11.0, 677.5, 12.3};
        vector<float> m_newballEntrance2 = {737.3, 339.6, 724.0, 351.2, 724.0, 353.4, 724.0, 355.6, 725.2, 356.8, 726.4, 358.0, 728.5, 358.0, 730.6, 358.0, 743.8, 346.4, 757.0, 334.9, 757.0, 332.6, 757.0, 330.4, 755.8, 329.2, 754.6, 328.0, 752.6, 328.0, 750.5, 328.0, 737.3, 339.6};
        vector<float> m_newballEntrance3 = {1034.2, 23.3, 1032.0, 25.6, 1032.0, 27.6, 1032.0, 29.7, 1034.3, 31.8, 1036.6, 34.0, 1045.6, 34.0, 1054.7, 34.0, 1056.8, 31.7, 1059.0, 29.4, 1059.0, 27.4, 1059.0, 25.3, 1056.7, 23.2, 1054.4, 21.0, 1045.4, 21.0, 1036.3, 21.0, 1034.2, 23.3};
        vector<float> m_newballEntrance4 = {692.5, 450.3, 684.0, 461.7, 684.0, 462.7, 684.0, 463.8, 687.5, 466.5, 691.1, 469.2, 692.4, 468.7, 693.8, 468.2, 701.5, 457.4, 709.3, 446.6, 709.7, 444.9, 710.2, 443.3, 707.4, 441.1, 704.7, 439.0, 702.9, 439.0, 701.0, 439.0, 692.5, 450.3};
        vector<float> m_underLayerUp = {737.2, 18.7, 736.5, 20.5, 736.5, 29.5, 736.5, 38.5, 754.0, 38.5, 771.5, 38.5, 771.5, 28.0, 771.5, 17.5, 754.7, 17.2, 738.0, 17.0, 737.2, 18.7};
        vector<float> m_topRailEntrance = {1091.5, 443.2, 1086.5, 444.1, 1085.6, 445.0, 1084.8, 445.8, 1085.9, 459.7, 1087.1, 473.5, 1088.0, 474.4, 1088.9, 475.3, 1096.7, 474.1, 1104.5, 472.9, 1105.4, 472.0, 1106.3, 471.1, 1104.1, 457.5, 1102.0, 443.8, 1101.4, 442.9, 1100.9, 442.0, 1098.7, 442.1, 1096.5, 442.2, 1091.5, 443.2};
        // Access this vector by index of rampID to get the collision shape for that ramp
        vector<vector<float>> m_rampShapes = {
            m_ramp1, m_ramp1up2, m_ramp1Down, m_hole1, m_ramp2, m_ramp2up2, m_ramp2Down, m_hole2, m_ramp3, m_ramp3Down, m_ramp3up2, m_backdoorDown, m_tunnelDown, m_newballEntrance2, m_newballEntrance3, m_newballEntrance4, m_underLayerUp, m_topRailEntrance
        };
};

#endif