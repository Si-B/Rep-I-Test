<?xml version="1.0" encoding="UTF-8"?>
<xsl:stylesheet version="1.0" xmlns:xsl="http://www.w3.org/1999/XSL/Transform">
	<xsl:output method="xml" encoding="UTF-8" indent="yes"/>
	<xsl:template match="/">
		<fo:root xmlns:fo="http://www.w3.org/1999/XSL/Format" xmlns:axf="http://www.antennahouse.com/names/XSL/Extensions">
			<fo:layout-master-set>
				<fo:simple-page-master master-name="PageMaster" page-height="210.00mm" page-width="297.00mm">
					<fo:region-body margin-bottom="30.00mm" margin-top="30.00mm" margin-left="30.00mm" margin-right="30.00mm"/>
					<fo:region-before display-align="after"/>
					<fo:region-after display-align="before"/>
				</fo:simple-page-master>
			</fo:layout-master-set>
			<fo:page-sequence master-reference="PageMaster" force-page-count="no-force">
				<fo:flow flow-name="xsl-region-body">
					<xsl:for-each select="/waffen">
						<fo:block>
							<fo:block-container>
								<fo:block-container font-family="Arial" font-size="12.00pt">
									<fo:table width="145.79mm" table-layout="fixed" start-indent="14.45mm">
										<fo:table-column column-width="72.89mm"/>
										<fo:table-column column-width="72.89mm"/>
										<fo:table-header start-indent="0pt">
											<fo:table-row height="6.44mm">
												<fo:table-cell>
													<fo:block-container height="6.44mm" overflow="condense">
														<fo:block start-indent="0pt"></fo:block>
													</fo:block-container>
												</fo:table-cell>
												<fo:table-cell>
													<fo:block-container>
														<fo:block start-indent="0pt"></fo:block>
													</fo:block-container>
												</fo:table-cell>
											</fo:table-row>
										</fo:table-header>
										<fo:table-body start-indent="0pt">
											<xsl:for-each select="/waffen/waffe">
												<fo:table-row height="6.44mm">
													<fo:table-cell>
														<fo:block-container height="6.44mm" overflow="condense">
															<fo:block start-indent="0pt">
																<xsl:value-of select="laufendeNummer"/>
															</fo:block>
														</fo:block-container>
													</fo:table-cell>
													<fo:table-cell>
														<fo:block-container>
															<fo:block start-indent="0pt">
																<xsl:value-of select="ueberlasser"/>
															</fo:block>
														</fo:block-container>
													</fo:table-cell>
												</fo:table-row>
											</xsl:for-each>
										</fo:table-body>
									</fo:table>
								</fo:block-container>
							</fo:block-container>
						</fo:block>
					</xsl:for-each>
				</fo:flow>
			</fo:page-sequence>
		</fo:root>
	</xsl:template>
</xsl:stylesheet>
