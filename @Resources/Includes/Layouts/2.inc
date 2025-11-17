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

; Brightness Section
[Brightness_Icon]
Meter=Image
ImagePath=#@#Images\Brightness
ImageName=3.png
X=(30*#Scale#)
Y=(30*#Scale#)
W=(24*#Scale#)
H=(24*#Scale#)
ImageTint=#Font_Color#
DynamicVariables=1

[Brightness_Label]
Meter=String
X=(60*#Scale#)
Y=(25*#Scale#)
Text=Brightness
FontSize=(18*#Scale#)
FontWeight=600
MeterStyle=Text_Style
DynamicVariables=1

[Brightness_Value_Text]
Meter=String
X=((#Background_Width#-30)*#Scale#)
Y=(25*#Scale#)
Text=[Measure_Backlight]%
FontSize=(18*#Scale#)
FontWeight=700
FontColor=#Accent_Color#
MeterStyle=Text_Style
StringAlign=Right
DynamicVariables=1

[Brightness_Slider_Track]
Meter=Shape
X=(#Slider_X#*#Scale#)
Y=(80*#Scale#)
Shape=Rectangle 0,0,(#Slider_Width#*#Scale#),(#Slider_Height#*#Scale#),(#Slider_Height#/2*#Scale#) | Fill Color #Slider_Track_Color# | StrokeWidth 0
Shape2=Rectangle 0,0,(Clamp([Slider_Drag_Calc]*[Slider_Size_Calc],0,(#Slider_Width#*#Scale#))),(#Slider_Height#*#Scale#),(#Slider_Height#/2*#Scale#) | Fill Color #Slider_Fill_Color# | StrokeWidth 0
LeftMouseDownAction=[!CommandMeasure Measure_Backlight "SetBacklight $MouseX:%$"][!UpdateMeter *][!Redraw]
DynamicVariables=1

[Brightness_Slider_Thumb]
Meter=Shape
X=(#Slider_X#*#Scale#)
Y=(80*#Scale#)
Shape=Ellipse (#Slider_Thumb_Size#/2*#Scale#),(#Slider_Thumb_Size#/2*#Scale#),(#Slider_Thumb_Size#/2*#Scale#) | Fill Color #Accent_Color# | StrokeWidth 0 | Offset (Clamp([Slider_Drag_Calc]*[Slider_Size_Calc],0,(#Slider_Width#*#Scale#))),(-(#Slider_Thumb_Size#/2*#Scale#)+(#Slider_Height#/2*#Scale#))
MouseOverAction=[!CommandMeasure Measure_Mouse_Brightness "Start"]
DynamicVariables=1

; Divider Line
[Divider_Line]
Meter=Shape
X=(30*#Scale#)
Y=(110*#Scale#)
Shape=Rectangle 0,0,((#Background_Width#-60)*#Scale#),(1*#Scale#),0 | Fill Color #Divider_Color# | StrokeWidth 0
DynamicVariables=1
; NightLight Section

[NightLight_Icon]
Meter=Image
ImageName=#@#Images\NightLight\[Measure_NightLight].png
X=(30*#Scale#)
Y=(140*#Scale#)
W=(24*#Scale#)
H=(24*#Scale#)
ImageTint=#Font_Color#
DynamicVariables=1

[NightLight_Label]
Meter=String
X=(60*#Scale#)
Y=(135*#Scale#)
Text=Night Light
FontSize=(18*#Scale#)
FontWeight=600
MeterStyle=Text_Style
DynamicVariables=1

[NightLight_Toggle]
Meter=Shape
X=((#Background_Width#-80)*#Scale#)
Y=(140*#Scale#)
Shape=Rectangle 0,0,(48*#Scale#),(26*#Scale#),(13*#Scale#) | StrokeWidth 0 | Extend This
Shape2=Ellipse (13*#Scale#),(13*#Scale#),(9*#Scale#) | Fill Color 255,255,255 | StrokeWidth 0 | Offset ([Measure_NightLight]*22*#Scale#),0
MeterStyle=NightLight_Shape_Style_[Measure_NightLight]
DynamicVariables=1
