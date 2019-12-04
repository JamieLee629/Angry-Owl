# Angry-Owl
ECE4180 Fall 2019 Final Project, Georgia Institute of Technology\
Project Members: Jamie Lee, Jingyi Yu

## Summary
A motion-detecting owl scarecrow controlled by a Raspberry Pi 3 Model B. Can move forwards and backwards, rotate, make scary sounds, flap wings, and shine bright lights in the presence of live garden pests such as rodents and deer. The purpose is to scare away these pests which eat the leaves, fruits and vegetables of garden crops.

## Background Information
My dad maintains a large garden, but pests like raccoons and deer will often eat the fruits of his labor. He has tried store-bought deer repellent, but it did not work. It would be useful for gardeners if there was an infrared-detecting scarecrow that can move when it detects a sudden change in infrared radiation levels (i.e. an animal coming into view). Additionally, the scarecrow can make customizable sounds that can scare the animals away. We decided to build our scarecrow in the form of an angry owl. The owl is a common predator among smaller pests, so the form of its silhouette alone can intimidate them. The loud sounds and commotion that the angry owl generates serves to scare off larger pests, such as deer and foxes.

## Electronics Parts List:
- 1x [Raspberry Pi 3 Model B](https://www.raspberrypi.org/products/raspberry-pi-3-model-b/)
- 1x Bare-Minimum RedBot Robot Kit
  - *The Bare-Minimum RedBot Robot Kit Contains:*
    - 1x [6" 3-Wire Cable](https://www.sparkfun.com/products/13164)
    - 1x [Pair of Wheels](https://www.sparkfun.com/products/13259)
    - 1x [Pair of 140-RPM Hobby Gearmotors](https://www.sparkfun.com/products/13302)
    - 1x [Shadow Chassis](https://www.sparkfun.com/products/13301)
- 1x [Speaker bonnet and Speakers](https://www.adafruit.com/product/3346)
- 2x [Super Bright White 5mm LED for eyes](https://www.adafruit.com/product/754)
- 3x [PIR Motion Sensors](https://www.adafruit.com/product/189)
- 1x [Raspberry Pi Camera Module V2](https://www.raspberrypi.org/products/camera-module-v2/)
- 1x [HS-422 Servo (Clockwise, Stock Rotation)](https://www.servocity.com/hs-422-servo#258=24&259=25)
- 1x [Pair of 140-RPM Hobby Gearmotors (for wing movement)](https://www.sparkfun.com/products/13302)
- 1x Dual-H Bridge Module

## Structural Parts List
- An empty coffee can for the owl's body
- Cardboard for owl wings and face
- Access to drilling equipment

## Instructions
1. Assemble the bare-minimum RedBot Robot Kit by following [Step 2 (Motors and Wheels)](https://learn.sparkfun.com/tutorials/assembly-guide-for-redbot-with-shadow-chassis/2-motors-and-wheels) and [Step 5 (Chassis)](https://learn.sparkfun.com/tutorials/assembly-guide-for-redbot-with-shadow-chassis/5-chassis) in the [Assembly Guide for RedBot with Shadow Chassis](https://learn.sparkfun.com/tutorials/assembly-guide-for-redbot-with-shadow-chassis).
2. Drill a hole in the bottom of the coffee can. Superglue the servo face plate to the bottom of the inside of the coffee can, with the flat side facing up and the nub fitting securely into the hole of the coffee can. The servo will be attached outside of the bottom of the coffee can later.
[add image here]
3. Prepare to set up the PIR motion sensors.
