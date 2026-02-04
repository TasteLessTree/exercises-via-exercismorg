#include <string.h>

#include "robot_simulator.h"

robot_status_t robot_create(robot_direction_t direction, int x, int y) {
    robot_status_t robot;
    robot_position_t position = {x, y};

    robot.direction = direction;
    robot.position = position;
    
    return robot;
}

void robot_move(robot_status_t *robot, const char *commands) {
    int len_commands = strlen(commands);
    robot_direction_t current_direction;
    
    for (int i = 0; i < len_commands; i++) {        
        switch (commands[i]) {
            case 'R':
                current_direction = robot->direction;
                switch (current_direction) {
                    case DIRECTION_MAX:
                    case DIRECTION_NORTH:
                        robot->direction = DIRECTION_EAST;
                        break;
    
                    case DIRECTION_EAST:
                        robot->direction = DIRECTION_SOUTH;
                        break;
                                
                    case DIRECTION_SOUTH:
                        robot->direction = DIRECTION_WEST;
                        break;
    
                    case DIRECTION_WEST:
                        robot->direction = DIRECTION_NORTH;
                        break;
    
                    default:
                        robot->direction = DIRECTION_EAST;
                        break;
                }
                break;

            case 'L':
                current_direction = robot->direction;
                switch (current_direction) {
                    case DIRECTION_MAX:
                    case DIRECTION_NORTH:
                        robot->direction = DIRECTION_WEST;
                        break;
    
                    case DIRECTION_WEST:
                        robot->direction = DIRECTION_SOUTH;
                        break;
                                
                    case DIRECTION_SOUTH:
                        robot->direction = DIRECTION_EAST;
                        break;
    
                    case DIRECTION_EAST:
                        robot->direction = DIRECTION_NORTH;
                        break;
    
                    default:
                        robot->direction = DIRECTION_WEST;
                        break;
                }
                break;

            case 'A':
                current_direction = robot->direction;
                switch (current_direction) {
                case DIRECTION_MAX:
                case DIRECTION_NORTH:
                    robot->position.y += 1;
                    break;

                case DIRECTION_WEST:
                    robot->position.x -= 1;
                    break;
                            
                case DIRECTION_SOUTH:
                    robot->position.y -= 1;
                    break;

                case DIRECTION_EAST:
                    robot->position.x += 1;
                    break;

                default:
                    robot->position.y += 1;
                    break;
                }
                break;
        }
    }
}