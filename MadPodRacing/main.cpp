#include <iostream>
#include <cmath>
#include <vector>

namespace math {

   class Vec2 {
   public:
      //coordinates
      int x;
      int y;

      Vec2() : x(0), y(0) {
      }

      Vec2(int x, int y) : x(x), y(y) {
      }

      //distance from (0,0) point
      double length() const {
         return std::sqrt(x * x + y * y);
      }

      //distance between this and v vectors
      double dist(Vec2& v) const {
         return std::sqrt((v.x - this->x) * (v.x - this->x) + (v.y - this->y) * (v.y - this->y));
      }

      //prefix increment
      Vec2& operator++() {
         ++x;
         ++y;
         return *this;
      }

      //postfix increment
      Vec2 operator++(int) {
         Vec2 v = *this;
         ++* this;
         return v;
      }

      //prefix decrement
      Vec2& operator--() {
         --x;
         --y;
         return *this;
      }

      //postfix decrement
      Vec2 operator--(int) {
         Vec2 v = *this;
         --* this;
         return v;
      }

      //add int
      Vec2 operator+(const int& n) {
         return Vec2(this->x + n, this->y + n);
      }

      //add vec2
      Vec2 operator+(const Vec2& v) {
         return Vec2(this->x + v.x, this->y + v.y);
      }

      //subtract int
      Vec2 operator-(const int& n) {
         return Vec2(this->x - n, this->y - n);
      }

      //subtract vec2
      Vec2 operator-(const Vec2& v) {
         return Vec2(this->x - v.x, this->y - v.y);
      }

      friend std::ostream& operator<<(std::ostream& os, const Vec2& v);
      friend std::istream& operator>>(std::istream& is, Vec2& v);
   };

   std::ostream& operator<<(std::ostream& os, const Vec2& v) {
      os << v.x << ' ' << v.y;
      return os;
   }

   std::istream& operator>>(std::istream& is, Vec2& v) {
      is >> v.x >> v.y;
      return is;
   }

   bool operator==(const math::Vec2& lhs, const math::Vec2& rhs) {
      return lhs.x == rhs.x && lhs.y == rhs.y;
   }
}

namespace game {
   class Checkpoint {
   private:
      //whether this checkpoint is next
      math::Vec2 m_position;
      bool m_flag;
      int m_pod_dist;
      int m_pod_angle;

   public:
      Checkpoint() : m_flag(false) {
      }

      Checkpoint(int x, int y, bool flag = false) : m_position(x, y), m_flag(false) {
      }

      Checkpoint(math::Vec2 position, bool flag = false) : m_position(position), m_flag(false) {
      }

      void setFlag(bool flag) {
         this->m_flag = flag;
      }

      bool getFlag() const {
         return m_flag;
      }

      math::Vec2 getPosition() const {
         return m_position;
      }

      friend std::ostream& operator<<(std::ostream& os, const Checkpoint& v);
      friend std::istream& operator>>(std::istream& is, Checkpoint& v);
   };

   std::ostream& operator<<(std::ostream& os, const Checkpoint& v) {
      os << v.getPosition();
      return os;
   }

   std::istream& operator>>(std::istream& is, Checkpoint& v) {
      v.setFlag(true);
      is >> v.m_position >> v.m_pod_dist >> v.m_pod_angle;
      return is;
   }

   bool operator==(const Checkpoint& lhs, const Checkpoint& rhs) {
      return lhs.getPosition() == rhs.getPosition();
   }

   class Pod : public math::Vec2 {

   };

   class Game {
   private:
      unsigned char lap = 1;
      Pod pod;
      Pod opponent;
      std::vector<Checkpoint> checkpoints;
      Checkpoint next_checkpoint;
   public:
      //game loop
      void mainLoop() {

         while (true) {
            std::cin >> pod >> next_checkpoint >> opponent;

            std::cout << next_checkpoint << " " << "100" << std::endl;
         }
      }
   };
}


int main()
{
   game::Game game;
   game.mainLoop();
   return 0;
}