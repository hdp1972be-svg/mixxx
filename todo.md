# Todo

## Feature: Disk space low-warning popup

- At Mixxx startup (and/or while working) check the free space on the HDD.
- Rationale: Mixxx crashes when HDD free space is 0.
- Desired approach: a Qt popup warning like the other Mixxx popup warnings, but:
  - raise the popup window above all other screen layers;
  - do NOT set it active (no focus), so it does not block Mixxx operation;
  - net effect: shown raised on top, but non-blocking.

## CI: MKV/WebM TagLib 2.2 build verification

- Verify both matrix legs (TagLib 2.2 and 1.11) pass on the hdp fork after the
  taglib.h include fix and the libtag path canonicalization fix.
