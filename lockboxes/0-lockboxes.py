#!/usr/bin/python3
"""function named canUnlockAll"""


def canUnlockAll(boxes):
    """function that determines if all the boxes can be opened"""
    openboxes = [0]
    for key in openboxes:
        for box in boxes[key]:
            if box not in openboxes and box < len(boxes):
                openboxes.append(box)
    if len(openboxes) == len(boxes):
        return True
    return False
