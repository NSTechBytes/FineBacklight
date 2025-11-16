[Variables]
; -------------------------------- Positional -------------------------------- ;
Position=BR
MonitorIndex=1
XPad=0
YPad=0
PreserveTaskbarSpace=1
StayOnDesktop=0

Animated=1
EaseType=OutQuart
AniDir=Bottom
AniSteps=18
AnimationDisplacement=30

[p.Focus]
Measure=Plugin
Plugin=Focus

[Func]
Measure=Script
ScriptFile=#@#Scripts\Lua\Position.lua
UpdateDivider=1

;=========================================================================================================================================;
;                                                                   Animation                                                             ;
;=========================================================================================================================================;

[ActionTimer]
Measure=Plugin
Plugin=ActionTimer
DynamicVariables=1
ActionList1=Show | Repeat In,2,#AniSteps#
ActionList2=Repeat Out,2,#AniSteps# | Hide
In=[!CommandMeasure Func "TweenAnimation('in')"]
Out=[!CommandMeasure Func "TweenAnimation('out')"]
DefaultUpdateDivider=-1


[ACTIONLOAD]
Measure=String
OnUpdateAction=[!CommandMeasure ActionTimer "Execute 1"]
Disabled=1
Group=NUOL

[ACTIONUNLOAD]
Measure=String
OnUpdateAction=[!CommandMeasure ActionTimer "Execute 2"][!DisableMeasure #CURRENTSECTION#]
Disabled=1
Group=NUOL