#!/usr/bin/python3

<<<<<<< HEAD
def can_unlock_all(boxes):
    open_boxes = [0]

    for key in open_boxes:
        for box in boxes[key]:
            if box not in open_boxes and 0 <= box < len(boxes):
                open_boxes.append(box)

    return len(open_boxes) == len(boxes)
=======
def canUnlockAll(boxes):
    openboxes = [0]
    for key in openboxes:
        for box in boxes[key]:
            if box not in openboxes and box < len(boxes):
                openboxes.append(box)
    if len(openboxes) == len(boxes):
        return True
    return False
>>>>>>> 822714b9dc8fe4628b9da5056381cdcc39b3a8b3
