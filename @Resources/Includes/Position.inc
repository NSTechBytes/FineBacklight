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