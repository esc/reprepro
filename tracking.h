#ifndef REPREPRO_TRACKING_H
#define REPREPRO_TRACKING_H


#ifndef REPREPRO_REFERENCE_H
#include "reference.h"
#endif
#ifndef REPREPRO_TRACKINGT_H
#include "trackingt.h"
#endif
#ifndef REPREPRO_DISTRIBUTION_H
#include "distribution.h"
#endif



retvalue tracking_parse(/*@null@*//*@only@*/char *option,struct distribution *);

retvalue tracking_initialize(/*@out@*/trackingdb *,const char *dbpath,const struct distribution *);
retvalue tracking_done(trackingdb);

retvalue trackedpackage_addfilekey(trackingdb,struct trackedpackage *,enum filetype,const char *filekey,references);
retvalue trackedpackage_addfilekeys(trackingdb,struct trackedpackage *,enum filetype,const struct strlist *filekeys,references);
retvalue trackedpackage_removefilekeys(trackingdb,struct trackedpackage *,const struct strlist *);
void trackedpackage_free(struct trackedpackage *pkg);

retvalue tracking_get(trackingdb,const char *name,const char *version,/*@out@*/struct trackedpackage **);
retvalue tracking_new(trackingdb,const char *name,const char *version,/*@out@*/struct trackedpackage **);
retvalue tracking_put(trackingdb,struct trackedpackage *);
retvalue tracking_replace(trackingdb,struct trackedpackage *);
retvalue tracking_remove(trackingdb,const char *sourcename,const char *version,references,/*@null@*/struct strlist *unreferencedfilekeys);
retvalue tracking_clearall(trackingdb);
retvalue tracking_printall(trackingdb t);

retvalue trackingdata_remember(struct trackingdata*,/*@only@*/char*,/*@only@*/char*);

retvalue trackingdata_summon(trackingdb,const char*,const char*,struct trackingdata *);
retvalue trackingdata_new(trackingdb,struct trackingdata *);
retvalue trackingdata_insert(struct trackingdata *,enum filetype,const struct strlist *filekeys,/*@null@*//*@only@*/char*oldsource,/*@null@*//*@only@*/char*oldversion,/*@null@*/const struct strlist *oldfilekeys, references);
retvalue trackingdata_remove(struct trackingdata *,/*@only@*/char*oldsource,/*@only@*/char*oldversion,const struct strlist *filekeys);
void trackingdata_done(struct trackingdata *);
#endif /*REPREPRO_TRACKING_H*/