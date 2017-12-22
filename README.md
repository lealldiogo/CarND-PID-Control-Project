# CarND-Controls-PID

This project was developed as part of the Udacity Self-Driving Car Engineer Nanodegree Program. The goal was to develop a PID controller to drive a lap around the track of the simulator

---

## Overview

One of the most known and used types of controllers is the proportional–integral–derivative (PID). By only tuning three different gains, it allows us to have a wide range of behaviors. Using it to control our cross-track error, the car was able to drive itself around the track.

## Environment Setup

Instructions for setting up the environment can be found [here](setup.md). After compiling, run the executable and open the simulator on the PID controller project to check it out.

## Implementation

The PID controller was implemented to obtain the steering angle from the cross-track error, which is the distance of the car to center of the track, using the following equation
```
steering_angle = Kp*p_error + Ki*i_error + Kd*d_error
```
where `Kp` is the proportional gain, `Ki` is the integral gain and `Kd` is the derivative gain each multiplied by the related error. All of them set to negative as I wanted the steering angle to be inversely proportional to the errors.

Assuming I wouldn't need to compensate for any error of the system, I knew from the beginning `Ki` would have to be very small. Aiming for a smooth ride, I also tuned `Kd` bigger than `Kp` so the variation of the cross-track error would have a bigger impact on the final result than the error by itself.

With that in mind, I started to manually tune the parameters and at first I tried to see how `Kp = -0.5`, `Ki = 0` and `Kd = -0.5` would drive the car. Even though it started out ok, it started to increase the amplitude of its steering until it actually drove of the track coming back to it only to drive in the opposite direction as seen in the picture:

[!first_params](first_params.png)

After that I decided to try tuning with the gains from the PID Implementation Quiz from the PID Control Lesson. By setting `Kp = -0.2`, `Ki = -0.004` and `Kd = -3.0` I was able to make the car drive itself around the track! To make the ride a little smoother, I doubled the derivative gain and ended up with `Kp = -0.2`, `Ki = -0.004` and `Kd = -6.0`.

I also tried with calculating the parameters using Twiddle in the Parameter Optimization Quiz, but it didn't work so well. I think that is because twiddle optimizes for a better final error and doesn't care about any overshooting.

## Improvements

Even after tuning the ride was not so smooth. Some more time could be spent manually tuning or running it on an optimization algorithm like twiddle or SGD aiming for a lower value for the derivative error could also achieve the goal of having a smooth ride.

Also, since the steering is sensitive to the speed, the gains could be set to vary with the speed.

### Author

Diogo Loreto Leal, Self-Driving Car Engineer Nanodegree Student


