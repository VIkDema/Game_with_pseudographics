//
// Created by vikto on 23.11.2020.
//

#ifndef MYGAME_ENEMY_H
#define MYGAME_ENEMY_H

class IEnemy {
public:
    virtual ~IEnemy() {};
    virtual int get_size() const = 0;

    virtual int get_damage() const = 0;

    virtual void set_cord_x(int x) = 0;

    virtual void set_cord_y(int y) = 0;

    virtual int get_cord_x() const = 0;

    virtual int get_cord_y() const = 0;

    virtual int get_speed() const = 0;

    virtual void print_enemy() = 0;
};

template<int damage, int size, int speed>
class Enemy : public IEnemy {
    int cord_x = 0;
    int cord_y = 0;
public:
    ~Enemy() override {

    };
    int get_size() const override {
        return size;
    }

    int get_damage() const override {
        return damage;
    }

    int get_speed() const override {
        return speed;
    }

    int get_cord_x() const override {
        return cord_x;
    }

    int get_cord_y() const override {
        return cord_y;
    }

    void set_cord_x(int x) override {
        cord_x = x;
    }

    void set_cord_y(int y) override {
        cord_y = y;
    }

    void print_enemy() override {
        if (size > 1) {
            std::cout << '#';
        } else if (speed > 2) {
            std::cout << '.';
        } else {
            std::cout << '-';
        }
    }
};




#endif //MYGAME_ENEMY_H
