;============================================================
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
;============================================================
;=============================================================
;           MeterStyles
;=============================================================

[NightLight_Shape_Style_0]
This=FillColor #NightLight_Off_Color#,#NightLight_Off_Opacity#
LeftMouseUpAction=[!CommandMeasure Measure_NightLight "Enable"][!UpdateMeter *][!Redraw]
MouseOverAction=[!SetOption #CURRENTSECTION# This "FillColor #NightLight_Off_Color#,#NightLight_Off_Hover_Opacity#"][!UpdateMeter #CURRENTSECTION#][!Redraw]
MouseLeaveAction=[!SetOption #CURRENTSECTION# This "FillColor #NightLight_Off_Color#,#NightLight_Off_Opacity#"][!UpdateMeter #CURRENTSECTION#][!Redraw]

[NightLight_Shape_Style_1]
This=FillColor #NightLight_On_Color#,#NightLight_On_Opacity#
LeftMouseUpAction=[!CommandMeasure Measure_NightLight "Disable"][!UpdateMeter *][!Redraw]
MouseOverAction=[!SetOption #CURRENTSECTION# This "FillColor #NightLight_On_Color#,#NightLight_On_Hover_Opacity#"][!UpdateMeter #CURRENTSECTION#][!Redraw]
MouseLeaveAction=[!SetOption #CURRENTSECTION# This "FillColor #NightLight_On_Color#,#NightLight_On_Opacity#"][!UpdateMeter #CURRENTSECTION#][!Redraw]

[Text_Style]
FontColor=#Font_Color#
FontFace=#Font_Face#
FontWeight=#Font_Weight#
Antialias=1
StringAlign=Left
;=============================================================
;           Content
;=============================================================

[Background_Shape]
Meter=Shape
Shape=Rectangle 0,0,(#Background_Width#*#Scale#),(#Background_Height#*#Scale#),#Background_Corner_Round# | StrokeWidth 0 | FillColor #Background_Color#,#Background_Opacity#
DynamicVariables=1

[Skin_Name_Title]
Meter=String
X=(20*#Scale#)
Y=(28*#Scale#)
Text=#Skin_Name#
FontSize=(18*#Scale#)
MeterStyle=Text_Style
;NightLight Shape Contents

[NightLight_Shape]
Meter=Shape
X=((#Background_Width#*#Scale#)-(150*#Scale#))
Y=(20*#Scale#)
Shape=Rectangle 0,0,(130*#Scale#),(40*#Scale#),(20*#Scale#) | StrokeWidth 1 | StrokeColor 200,200,200,100 | Extend This
MeterStyle=NightLight_Shape_Style_[Measure_NightLight]
DynamicVariables=1

[NightLight_Icon]
Meter=Image
ImageName=#@#Images\NightLight\[Measure_NightLight].png
X=((#Background_Width#*#Scale#)-(140*#Scale#))
Y=(30*#Scale#)
W=(20*#Scale#)
H=(20*#Scale#)
DynamicVariables=1

[NightLight_Title]
Meter=String
X=((#Background_Width#*#Scale#)-(110*#Scale#))
Y=(30*#Scale#)
Text=NightLight
FontSize=(12*#Scale#)
MeterStyle=Text_Style

[Brightness_Icon]
Meter=Image
ImagePath=#@#Images\Brightness
ImageName=3.png
X=(20*#Scale#)
Y=(98*#Scale#)
W=(30*#Scale#)
H=(30*#Scale#)
DynamicVariables=1

[Brightness_Slider_Track]
Meter=Shape
X=(#Slider_X#*#Scale#)
Y=(110*#Scale#)
Shape=Rectangle 0,0,(#Slider_Width#*#Scale#),(#Slider_Height#*#Scale#),(#Slider_Height#/2*#Scale#) | Fill Color #Slider_Track_Color# | StrokeWidth 0
Shape2=Rectangle 0,0,(Clamp([Slider_Drag_Calc]*[Slider_Size_Calc],0,(#Slider_Width#*#Scale#))),(#Slider_Height#*#Scale#),(#Slider_Height#/2*#Scale#) | Fill Color #Slider_Fill_Color# | StrokeWidth 0
LeftMouseDownAction=[!CommandMeasure Measure_Backlight "SetBacklight $MouseX:%$"][!UpdateMeter *][!Redraw]
DynamicVariables=1

[Brightness_Slider_Thumb]
Meter=Shape
X=(#Slider_X#*#Scale#)
Y=(110*#Scale#)
Shape=Ellipse (#Slider_Thumb_Size#/2*#Scale#),(#Slider_Thumb_Size#/2*#Scale#),(#Slider_Thumb_Size#/2*#Scale#) | Fill Color 255,255,255 | StrokeWidth (1*#Scale#) | Stroke Color 204,204,204 | Offset (Clamp([Slider_Drag_Calc]*[Slider_Size_Calc],0,(#Slider_Width#*#Scale#))),(-(#Slider_Thumb_Size#/2*#Scale#)+(#Slider_Height#/2*#Scale#))
MouseOverAction=[!CommandMeasure Measure_Mouse_Brightness "Start"]
DynamicVariables=1

[Brightness_Value_Text]
Meter=String
X=((#Slider_X#+#Slider_Width#+70)*#Scale#)
Y=(100*#Scale#)
Text=[Measure_Backlight]%
FontSize=(14*#Scale#)
MeterStyle=Text_Style
StringAlign=Right
DynamicVariables=1
