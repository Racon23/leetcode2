/*
 * @lc app=leetcode.cn id=1603 lang=cpp
 *
 * [1603] 设计停车系统
 */

// @lc code=start
class ParkingSystem
{
    int big_;
    int medium_;
    int small_;

public:
    ParkingSystem(int big, int medium, int small)
    {
        big_ = big;
        medium_ = medium;
        small_ = small;
    }

    bool addCar(int carType)
    {
        switch(carType){
            case 1:
                return big_>0&&big_--;
            case 2:
                return medium_>0&&medium_--;
            case 3:
                return small_>0&&small_--;
        }
        return false;
    }
};

/**
 * Your ParkingSystem object will be instantiated and called as such:
 * ParkingSystem* obj = new ParkingSystem(big, medium, small);
 * bool param_1 = obj->addCar(carType);
 */
// @lc code=end
