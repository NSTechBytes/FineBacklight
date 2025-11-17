; ============================================================
;  NuraShade Skin
;  Copyright (c) 2025 NuraShade
;
;  Licensed under the Creative Commons Attribution-ShareAlike 3.0 Unported License.
;  You are free to:
;    • Share — copy and redistribute the material in any medium or format
;    • Adapt — remix, transform, and build upon the material
;      for any purpose, even commercially.
;
;  Under the following terms:
;    • Attribution — You must give appropriate credit, provide a link to the license,
;      and indicate if changes were made.
;    • ShareAlike — If you remix, transform, or build upon the material,
;      you must distribute your contributions under the same license as the original.
;
;  License Details: https://creativecommons.org/licenses/by-sa/3.0/
; ============================================================
[Variables]
Use_As_Widget=1
;Position
Position=BR
Monitor_Index=1
X_Padding=0
Y_Padding=0
Preserve_Taskbar_Space=1
;Animation
Animated=1
Ease_Type=OutQuart
Animation_Direction=Bottom
Animation_Steps=18
Animation_Displacement=30
;=============================================================
;           Measures
;=============================================================
[Measure_Focus]
Measure=Plugin
Plugin=Focus

[Measure_Position_Animation]
Measure=Script
ScriptFile=#@#Scripts\Lua\Position.lua
UpdateDivider=1

[Measure_Position_Animation_Timer]
Measure=Plugin
Plugin=ActionTimer
DynamicVariables=1
ActionList1=Show | Repeat In,2,#Animation_Steps#
ActionList2=Repeat Out,2,#Animation_Steps# | Hide
In=[!CommandMeasure Measure_Position_Animation "TweenAnimation('in')"]
Out=[!CommandMeasure Measure_Position_Animation "TweenAnimation('out')"]
DefaultUpdateDivider=-1
