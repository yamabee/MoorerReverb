/* =========================================================================================

   This is an auto-generated file: Any edits you make may be overwritten!

*/

#pragma once

namespace BinaryData
{
    extern const char*   MetallicBG_png;
    const int            MetallicBG_pngSize = 183158;

    extern const char*   MetallicBGwithGuide_png;
    const int            MetallicBGwithGuide_pngSize = 595835;

    extern const char*   MoorerBackground_png;
    const int            MoorerBackground_pngSize = 868781;

    extern const char*   pinkDialKnob_png;
    const int            pinkDialKnob_pngSize = 330824;

    extern const char*   PultecKnobs_png;
    const int            PultecKnobs_pngSize = 268587;

    extern const char*   smallPinkGlowKnob_png;
    const int            smallPinkGlowKnob_pngSize = 201112;

    extern const char*   smallPurpleKnob_png;
    const int            smallPurpleKnob_pngSize = 512042;

    extern const char*   VintageKnob_png;
    const int            VintageKnob_pngSize = 1405796;

    extern const char*   VSTKnob64_png;
    const int            VSTKnob64_pngSize = 1159105;

    extern const char*   VSTKnobPurple121_png;
    const int            VSTKnobPurple121_pngSize = 3224998;

    // Number of elements in the namedResourceList and originalFileNames arrays.
    const int namedResourceListSize = 10;

    // Points to the start of a list of resource names.
    extern const char* namedResourceList[];

    // Points to the start of a list of resource filenames.
    extern const char* originalFilenames[];

    // If you provide the name of one of the binary resource variables above, this function will
    // return the corresponding data and its size (or a null pointer if the name isn't found).
    const char* getNamedResource (const char* resourceNameUTF8, int& dataSizeInBytes);

    // If you provide the name of one of the binary resource variables above, this function will
    // return the corresponding original, non-mangled filename (or a null pointer if the name isn't found).
    const char* getNamedResourceOriginalFilename (const char* resourceNameUTF8);
}
