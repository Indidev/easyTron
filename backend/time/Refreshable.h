#ifndef REFRESHABLE_H
#define REFRESHABLE_H

/**
 * @brief The Refreshable interface
 */
class Refreshable {
public:
    /**
     * tick will be called from a timer to refresh the child class
     */
    virtual void tick() = 0;
};

#endif // REFRESHABLE_H
