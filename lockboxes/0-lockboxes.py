#!/usr/bin/python3

def can_unlock_all(boxes):
    open_boxes = [0]

    for key in open_boxes:
        for box in boxes[key]:
            if box not in open_boxes and 0 <= box < len(boxes):
                open_boxes.append(box)

    return len(open_boxes) == len(boxes)