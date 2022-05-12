#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>

#include "../include/Vec2.h"

namespace math {


}

namespace game {
   class Checkpoint {
   private:
      //whether this checkpoint is next
      Vec2 m_position;
      int m_pod_dist;
      int m_pod_angle;
      bool m_flag;

   public:
      Checkpoint() : m_pod_dist(0), m_pod_angle(0), m_flag(false) {
      }

      Checkpoint(int x, int y, int pod_dist = 0, int pod_angle = 0, bool flag = false) : m_position(x, y), m_pod_dist(pod_dist), m_pod_angle(pod_angle), m_flag(false) {
      }

      Checkpoint(Vec2 position, int pod_dist = 0, int pod_angle = 0, bool flag = false) : Checkpoint(position.x, position.y, pod_dist, pod_angle, flag) {
      }

      void setPodDist(int pod_dist) {
         m_pod_dist = pod_dist;
      }

      int getPodDist() const {
         return m_pod_dist;
      }

      void setPodAngle(int pod_angle) {
         m_pod_angle = pod_angle;
      }

      int getPodAngle() const {
         return m_pod_angle;
      }

      void setFlag(bool flag) {
         this->m_flag = flag;
      }

      bool getFlag() const {
         return m_flag;
      }

      Vec2 getPosition() const {
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

   bool operator!=(const Checkpoint& lhs, const Checkpoint& rhs) {
      return lhs.getPosition() != rhs.getPosition();
   }

   class Pod : public Vec2 {
   };

   class Game {
   private:
      

   public:
      //game loop
      void mainLoop() {
         unsigned char lap = 0;
         Pod pod;
         Pod opponent;
         std::vector<Checkpoint> checkpoints;
         Checkpoint next_checkpoint;
         Checkpoint last_checkpoint;
         while (true) {
            std::cin >> pod >> next_checkpoint >> opponent;

            std::cerr << "Lap: " << (int)lap << std::endl;

            auto next_checkpoint_it = std::find(checkpoints.begin(), checkpoints.end(), next_checkpoint);

            //fill checkpoints vector
            if (next_checkpoint_it == checkpoints.end()) {
               checkpoints.push_back(next_checkpoint);
            }

            //increment lap
            if (next_checkpoint == checkpoints[0] && next_checkpoint != last_checkpoint) {
               ++lap;
            }

            for (int i = 0; i < checkpoints.size(); ++i) {
               std::cerr << "Checkpoint " << i << ": " << checkpoints[i] << std::endl;
            }

            std::cout << next_checkpoint << " " << "100" << std::endl;

            last_checkpoint = next_checkpoint;
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